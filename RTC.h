/*RTC.h*/

//from lc60test4 irq_clk.h 
void RTC_IRQ_init (void);
void Clock (void);
void Clock_bDisplay (void);
interrupt VectorNumber_Virq void IRQ_Interrupt (void);
void Get_Time(void);
//void Get_Date(void);      to be used when calendar program is done
//void Display_Date(void);  to be used when calendar program is done
void bDisplay_Time(unsigned char bDisplay_Status);

//from lc60test4 i2c_RTC.h
void IICRTC_InitWrite(void);
//void IICRTC_write (void);
void IICRTC_Clear_Flag (void);
void IICRTC_set_Pointer_00h(void);
void IICRTC_set_Pointer_01h(void);
void IICRTC_set_Pointer_02h(void);
void IICRTC_set_Pointer_04h(void);
void IICRTC_set_Pointer_05h(void);
byte IICRTC_Get_Data (void);

