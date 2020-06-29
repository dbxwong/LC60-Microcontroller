/*RTC.c

//from lc60test4 irq_clk.h 
void IRQ_Interrupt (void);
void RTC_IRQ_init (void);
void Clock (void);
void Clock_bDisplay (void);
void Get_Time(void);
//void Get_Date(void);     to be used when calendar program is done
//void bDisplay_Date(void); to be used when calendar program is done
void bDisplay_Time(unsigned char bDisplay_Status);

//from lc60test4 i2c_RTC.h
void IICRTC_write (void);
void IICRTC_Clear_Flag (void);
void IICRTC_set_Pointer_00h(void);
void IICRTC_set_Pointer_01h(void);
void IICRTC_set_Pointer_02h(void);
void IICRTC_set_Pointer_04h(void);
void IICRTC_set_Pointer_05h(void);
byte IICRTC_Get_Data (void);     */

#include "derivative.h"
#include <MC9S08LC60.h>
#include "RTC.h"
#include <hidef.h>
#include "Calendar.h"
#include "LCD_base.h"
#include "Delays.h"

//Declaration
extern unsigned int uiApps_Flag;
unsigned char ucHours_High=48; //Hours
unsigned char ucHours_Low=57;  
unsigned char ucMinutes_High=48;//Minutes
unsigned char ucMinutes_Low=48;
unsigned char ucSeconds_High=48; //Seconds
unsigned char ucSeconds_Low=48;  
//unsigned char Hour_High_Data, Hour_Low_Data,
byte x=0, Write_Enabled=0;
byte bDisplay = 0;

//declaration
unsigned char ucTen_ucSeconds_Data, ucSeconds_Data;
unsigned char ucTen_ucMinutes_Data, ucMinutes_Data; 
unsigned char Hour_Data;
//unsigned char Hour_High_Data, Hour_Low_Data,
unsigned char ucHour_MSB_Data;
unsigned char RTC_data_00h, RTC_data_01h, RTC_data_02h;

/*declaration
unsigned char Date, Month;  
unsigned char Date_High, Date_Low;
unsigned char Ten_Date_Data, Date_Data;
unsigned char Month_High, Month_Low;
unsigned char Ten_Month_Data, Month_Data;
*/

extern byte bADC_Sample;

interrupt VectorNumber_Virq void IRQ_Interrupt (void)
{
  
	Clock();
 
//	Clock_bDisplay(); 	
/*
	if(bDisplay == 1) 
	{
	  Clock_bDisplay();
	} 
	
	else if(bDisplay == 0)
	{
	  //LCDClear();
	  LCDClearSegment(xDADP,2);
	  LCDClearSegment(xDADP,3);
	  Keypad_Recall_bDisplay();	  
	} 
	
	else if(bDisplay == 3) 
	{
	   LCDClear(); 
	} */ 
  IRQSC_IRQACK = 1;     // Clear IRQ flag 
}  



//==============================================

void RTC_IRQ_init(void) 
{
  IICRTC_InitWrite();     // Set the RTC DAC DS1374C
  //Get_Time();          //cancelled for test
  PTCDD_PTCDD7 = 0;     // IRQ input PTC7
  IRQSC = 0x12;         // IRQ status register 
}

//==============================================

void IICRTC_InitWrite (void){ //to initialize RTC sets at 8.40am wed
byte i;

while(IICS_BUSY);       // Wait till bus is free 
	 IICC_TX = 1;         // Transmit Mode
   IICC_MST = 1;        // Send start bit
   IICD = 0b11010000;   // Transmit slave address 
   for (i=0; i<5; i++); // Delay 
   
   while(IICS_TCF==0);  // Wait till transfer is complete
   for (i=0; i<5; i++); // Delay 
   IICD= 0x00;          // Transmit word address 
   
   for (i=0; i<5; i++); // Delay 
   while(IICS_TCF==0);  // Wait till transfer is complete
   IICD= 0x00;          // Transmit 00h data (Seconds) 
   
   for (i=0; i<5; i++); // Delay
   while(IICS_TCF==0);  // Wait till transfer is complete
   IICD= 0x00;          // Transmit 01h data (Minutes)
   
   for (i=0; i<5; i++); // Delay 
   while(IICS_TCF==0);  // Wait till transfer is complete
   IICD= 0x00;          // Transmit 02h data (Hour)
   
   for (i=0; i<5; i++); // Delay
   while(IICS_TCF==0);  // Wait till transfer is complete
   IICD= 0x00;          // Transmit 03h data  (Day??)
   
   for (i=0; i<5; i++); // Delay 
   while(IICS_TCF==0);  // Wait till transfer is complete
   IICD= 0x00;          // Transmit 04h data (watchdog/alarm registers unused)
   
   for (i=0; i<5; i++); // Delay
   while(IICS_TCF==0);  // Wait till transfer is complete
   IICD= 0x00;          // Transmit 05h data (watchdog/alarm registers unused)
   
   for (i=0; i<5; i++); // Delay 
   while(IICS_TCF==0);  // Wait till transfer is complete
   IICD= 0x00;          // Transmit 06h data (watchdog/alarm registers unused)
   
   for (i=0; i<5; i++); // Delay
   while(IICS_TCF==0);  // Wait till transfer is complete
   IICD= 0x10;          // Transmit 07h data (set oscillator enable, 1Hz sq. wave output, diable all alarms)
   
   for (i=0; i<5; i++); // Delay 
   while(IICS_TCF==0);  // Wait till transfer is complete
   IICD= 0x00;          // Transmit 08h data
   
   for (i=0; i<5; i++); // Delay
   while(IICS_TCF==0);  // Wait till transfer is complete
   IICD= 0x00;//0xAA;          // Transmit 09h data    (Trickle charger circuit, set 1 diode 2kOhm resistor)
   
   for(i=0; i<5; i++);  // Delay
   while(IICS_TCF==0);  // Wait till transfer is complete
   IICC_MST=0;          // Generate stop signal     
}

void Clock (void) 
{

  if(x==0) 
  {     
    Write_Enabled = 1;
  } 
  
  if(x==1) 
  {   
    Write_Enabled = 0;
    x++;
  }
  
  ucSeconds_Low++;  
	
	if(ucSeconds_Low == 58)
	{
		ucSeconds_Low = 48;   // Reset back to 0
		ucSeconds_High++;				
	} 
	
	if((ucSeconds_High == 54) && (ucSeconds_Low == 48 ))
	{
		ucSeconds_High = 48;  // Reset back to zero
		ucSeconds_Low = 48;   // Reset back to zero
		ucMinutes_Low++;
	 
	} 
	
	if(ucMinutes_Low == 58)
	{
		ucMinutes_Low = 48;   // Reset back to 0
		ucMinutes_High++;				
	} 
	
	if((ucMinutes_High == 54) && (ucMinutes_Low == 48 ))
	{
		ucMinutes_High = 48;  // Reset back to zero
		ucMinutes_Low = 48;   // Reset back to zero
		ucHours_Low++;
	}
	
	if(ucHours_Low == 58)
	{
		ucHours_Low = 48;     // Reset back to 0
		ucHours_High++;				
	} 
	
	if((ucHours_High == 50) && (ucHours_Low == 52 ))
	{
		ucHours_High = 48;    // Reset back to zero
		ucHours_Low = 48;     // Reset back to zero
    
    Calendar_Update();
	}  
	
		
	//bDisplay Hours and Minutes and seconds
	/*
	Primary_LCDPutChar(ucSeconds_Low, 6);
	Primary_LCDPutChar(ucSeconds_High, 5);	
  Primary_LCDPutChar(ucMinutes_Low, 4);
	Primary_LCDPutChar(ucMinutes_High, 3);
  Primary_LCDPutChar(ucHours_Low, 2);
	Primary_LCDPutChar(ucHours_High, 1);
	*/
	
	if(x==0)x++;
	if(x==2)x=0;					
}

//==============================================
void Clock_bDisplay(void) 
{  
    
    //bDisplay Hours and Minutes and seconds
  	LCD_putChar(ucSeconds_Low, 6);
  	LCD_putChar(ucSeconds_High, 5);	
    LCD_putChar(ucMinutes_Low, 4);
  	LCD_putChar(ucMinutes_High, 3);
    LCD_putChar(ucHours_Low, 2);
  	LCD_putChar(ucHours_High, 1);
  	LCDWriteSegment(COLx, 1);
  	LCDWriteSegment(DTx, 4);   //decimal pt for seconds seperator
  	
  	
  
/*  	if(Write_Enabled == 1) 
  	{
  	  LCDWriteSegment(xDADP,2);
      LCDWriteSegment(xDADP,3);  
  	} 
  	
  	else if(Write_Enabled == 0) 
  	{
  	  LCDClearSegment(xDADP,2);
      LCDClearSegment(xDADP,3);  
  	}             */
}

//==============================================

void Get_Time(void) 
{  
    //===============Seconds=================
    IICRTC_set_Pointer_00h(); //Pointer Set to 0x01h
    RTC_data_00h = IICRTC_Get_Data();

    ucSeconds_Data = RTC_data_00h&(0x0F);
    ucSeconds_Low = ucSeconds_Data + 48;

    ucTen_ucSeconds_Data = ((RTC_data_00h&(0x70))>>4)&0x07;
    ucSeconds_High = ucTen_ucSeconds_Data + 48;
    
  
    //===============Minutes=================
    IICRTC_set_Pointer_01h(); //Pointer Set to 0x01h
    RTC_data_01h = IICRTC_Get_Data();

    ucMinutes_Data = RTC_data_01h&(0x0F);
    ucMinutes_Low = ucMinutes_Data + 48;

    ucTen_ucMinutes_Data = ((RTC_data_01h&(0x70))>>4)&0x07;
    ucMinutes_High = ucTen_ucMinutes_Data + 48;


    //================Hours==================
    IICRTC_set_Pointer_02h(); //Pointer Set to 0x02h
    RTC_data_02h = IICRTC_Get_Data();

    Hour_Data = RTC_data_02h&(0x0F);
    ucHours_Low = Hour_Data + 48;
    
    /*
    Hour_Low_Data = ((RTC_data_02h&(0x10))>>4)&0x01;
    Hour_High_Data = ((RTC_data_02h&(0x20))>>5)&0x01;
    
    
    if((Hour_High_Data==0)&&(Hour_Low_Data == 1))
    {
    	ucHours_High = 1 + 48;
    } 
    
    else if((Hour_High_Data == 1)&&(Hour_Low_Data == 1))
    {
    	ucHours_High = 2 + 48;
    } 
    
    else if((Hour_High_Data == 0)&&(Hour_Low_Data == 0))
    {
    	ucHours_High = 48;
    }    
    */
    
    ucHour_MSB_Data = ((RTC_data_02h&(0xF0))>>4)&0x0F;
    ucHours_High = ucHour_MSB_Data+48;
}

//=============================================
void bDisplay_Time(unsigned char bDisplay_Status) 
{
    bDisplay = bDisplay_Status;  
}

//==============================================
  /* FOR HARRY's BOARD RTC
  void IICRTC_write (void)
{
   byte i;   
       
   while(IICS_BUSY) ;   // Wait till bus is free 
	
   IICC_TX = 1;         // Transmit Mode
   IICC_MST = 1;        // Send start bit
   IICD = 0b11010000;   // Transmit slave address 
      
   for (i=0; i<5; i++); // Delay 

   while(IICS_TCF==0);  // Wait till transfer is complete
   
   for (i=0; i<5; i++); // Delay 
   
   IICD= 0x00;          // Transmit word address 
   
   for (i=0; i<5; i++); // Delay 
      
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x00;          // Transmit 00h data (Seconds) 
   
   for (i=0; i<5; i++); // Delay
      
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x16;          // Transmit 01h data (Minutes)
   
   for (i=0; i<5; i++); // Delay 
      
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x17;          // Transmit 02h data (Hour)
   
   for (i=0; i<5; i++); // Delay
      
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x04;          // Transmit 03h data  (Day)
   
   for (i=0; i<5; i++); // Delay 
      
   while(IICS_TCF==0);  // Wait till transfer is complete
   
   IICD= 0x17;          // Transmit 04h data (Date)
   
   for (i=0; i<5; i++); // Delay
      
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x07;          // Transmit 05h data (Month)
   
   for (i=0; i<5; i++); // Delay 
      
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x08;          // Transmit 06h data (Year)
   
   for (i=0; i<5; i++); // Delay
      
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x00;          // Transmit 07h data
   
   for (i=0; i<5; i++); // Delay 
      
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x00;          // Transmit 08h data
   
   for (i=0; i<5; i++); // Delay
      
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x00;          // Transmit 09h data
   
   for (i=0; i<5; i++); //Delay 
      
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x00;          // Transmit 0Ah data
   
   for (i=0; i<5; i++); // Delay 
   
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x00;          // Transmit 0Bh data
   
   for (i=0; i<5; i++); // Delay
   
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x00;          // Transmit 0Ch data
   
   for (i=0; i<5; i++); // Delay
   
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x00;          // Transmit 0Dh data
   
   for (i=0; i<5; i++); // Delay 
   
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x40;          // Transmit 0Eh data
   
   for (i=0; i<5; i++); // Delay
   
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x48;          // Transmit 0Fh data
   
   for (i=0; i<5; i++); // Delay
          
   while(IICS_TCF==0);  // Wait till transfer is complete

   IICC_MST=0;          // Generate stop signal     
 
}           */

//==============================================

   
void IICRTC_Clear_Flag (void) 
{
 byte i;   
       
   while(IICS_BUSY) ;   // Wait till bus is free 
	
   IICC_TX = 1;         // Transmit Mode
   IICC_MST = 1;        // Send start bit
   IICD = 0b11010000;   // Transmit slave address 
      
   for (i=0; i<5; i++); // Delay 

   while(IICS_TCF==0);  // Wait till transfer is complete 
   
   for (i=0; i<5; i++); // Delay 
   
   IICD= 0x0F;          // Transmit word address (SPR) 
   
   for (i=0; i<5; i++); // Delay 
      
   while(IICS_TCF==0);  // Wait till transfer is complete
 
   IICD= 0x48;          // Transmit 0Fh data 
   
   for (i=0; i<5; i++); // Delay
                      
   while(IICS_TCF==0);  // Wait till transfer is complete

   IICC_MST=0;          // Generate stop signal     
   
}

//==============================================


void IICRTC_set_Pointer_00h(void)
{
   byte i;
       
   while(!IICS_TCF) ;   // Wait till transfer is complete 
	
   IICC_TX = 1;         // Transmit Mode
   IICC_MST = 1;        // Send start bit
   IICD = 0b11010000;   // Transmit slave address 
      
   for (i=0; i<5; i++); // Delay 

   while(IICS_TCF==0);  // Wait till transfer is complete 
   
   for (i=0; i<5; i++); // Delay 
   
   IICD= 0x00;          // Transmit word address  
   
   for (i=0; i<5; i++); // Delay 
                            
   while(IICS_TCF==0);  // Wait till transfer is complete

   IICC_MST=0;          // Generate stop signal       
}

//==============================================
void IICRTC_set_Pointer_01h(void)
{
   byte i;
       
   while(!IICS_TCF) ;   // Wait till transfer is complete 
	
   IICC_TX = 1;         // Transmit Mode
   IICC_MST = 1;        // Send start bit
   IICD = 0b11010000;   // Transmit slave address 
      
   for (i=0; i<5; i++); // Delay 

   while(IICS_TCF==0);  // Wait till transfer is complete 
   
   for (i=0; i<5; i++); // Delay 
   
   IICD= 0x01;          // Transmit word address  
   
   for (i=0; i<5; i++); // Delay 
                            
   while(IICS_TCF==0);  // Wait till transfer is complete

   IICC_MST=0;          // Generate stop signal       
}

//==============================================
void IICRTC_set_Pointer_02h(void)
{
   byte i;
       
   while(!IICS_TCF) ;   // Wait till transfer is complete 
	
   IICC_TX = 1;         // Transmit Mode
   IICC_MST = 1;        // Send start bit
   IICD = 0b11010000;   // Transmit slave address 
      
   for (i=0; i<5; i++); // Delay 

   while(IICS_TCF==0);  // Wait till transfer is complete 
   
   for (i=0; i<5; i++); // Delay 
   
   IICD= 0x02;          // Transmit word address  
   
   for (i=0; i<5; i++); // Delay 
                            
   while(IICS_TCF==0);  // Wait till transfer is complete

   IICC_MST=0;          // Generate stop signal       
}
//==============================================

void IICRTC_set_Pointer_04h(void)
{
   byte i;
       
   while(!IICS_TCF) ;   // Wait till transfer is complete 
	
   IICC_TX = 1;         // Transmit Mode
   IICC_MST = 1;        // Send start bit
   IICD = 0b11010000;   // Transmit slave address 
      
   for (i=0; i<5; i++); // Delay 

   while(IICS_TCF==0);  // Wait till transfer is complete 
   
   for (i=0; i<5; i++); // Delay 
   
   IICD= 0x04;          // Transmit word address  
   
   for (i=0; i<5; i++); // Delay 
                            
   while(IICS_TCF==0);  // Wait till transfer is complete

   IICC_MST=0;          // Generate stop signal       
}

//==============================================

void IICRTC_set_Pointer_05h(void)
{
   byte i;
       
   while(!IICS_TCF) ;   // Wait till transfer is complete  
	
   IICC_TX = 1;         // Transmit Mode
   IICC_MST = 1;        // Send start bit
   IICD = 0b11010000;   // Transmit slave address 
      
   for (i=0; i<5; i++); // Delay 

   while(IICS_TCF==0);  // Wait till transfer is complete 
   
   for (i=0; i<5; i++); // Delay 
   
   IICD= 0x05;          // Transmit word address  
   
   for (i=0; i<5; i++); // Delay 
                            
   while(IICS_TCF==0);  // Wait till transfer is complete

   IICC_MST=0;          // Generate stop signal       
}
//==============================================

byte IICRTC_Get_Data (void)
{
   unsigned char i, Data;
	
   while(!IICS_TCF) ;   // Wait till transfer is complete 	      
   IICC_TX = 1;         // Transmit Mode 
   IICC_MST = 1;        // Send start bit
  
   IICD = 0b11010001;   // Transmit slave address (read)        
   for(i=0; i<5; i++);   
   while(IICS_TCF==0);  // Wait till transfer is complete  
  
   IICC_TX = 0;         // Receive Mode
   
   //=================
   Data = IICD;         // Dummy Read
   for(i=0; i<5; i++);
   while(IICS_TCF==0);
   //=================
   
   IICC_TXAK = 1;       // No acknowledge will be sent out
   
   for(i=0; i<5; i++);  // Delay
   
   Data = IICD;         // Read the data in IIC data register
  
   for(i=0; i<5; i++);  // Delay
  
   while(IICS_TCF==0);  // Wait till transfer is complete
          
   for(i=0; i<5; i++);  // Delay
   
   IICC_MST=0;          // Generate stop signal   
                        
   return Data;   
}






