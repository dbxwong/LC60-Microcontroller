/*ADC object for Demo Bd
12-bit ADC; 8 user channels (PortA) (24-ch Successive Approxn)
ADC Clk range:2-5 MHz for high speed;1.25-3.3 MHz for low pwr
Sample time (ADC clk cycles) Short=3.5; Long=23.5 
• ADCSC1,ADCSC2  Status and control register, 
• ADCRH, ADCRL    Data result registers, 
• ADCCVH,ADCCVL   Compare value registers, 
• ADCCFG,         Configuration register, 
• APCTL1,APCTL2,APCTL3  Pin enable registers,

Usage Example:
  ADC_Base_init(); //Turn on ADC module
  ADC_connectCh(0);//Connect ADC to pin AD0 for AD conversion
  uiResult=ADC_convRead_uiData(0);//digitize signal(12-bit) at AD0 

ADC Pin   Alt               IC      Demo  Demo Bd
Ch  Name  Func              80pins  J101  Device
--- ----  -----------       ------  ----  -------------
0   AD0   PTA0/KBI1P0       p18     p10   Potentiometer
1   AD1   PTA1/KBI1P1       p19     p12   Photocell
2   AD2   PTA2/KBI1P2/ACMP+ p20     p14   Accelerometer_X
3   AD3   PTA3/KBI1P3/ACMP- p21     p16   Accelerometer_Y

4   AD4   PTA4/KBI1P4       p22     p18   Accelerometer_Z
5   AD5   PTA5/KBI1P5       p23     p20   Led6
6   AD6   PTA6/KBI1P6       p24     p22   Led7
7   AD7   PTA7/KBI1P7       p25     p24   Led8/Thermistor

Usage Example:
  unsigned char ucADC_Data;
  ADC_Base_init(); //Turn on ADC module
  ADC_connectCh(AD0);//Connect ADC to pin AD0 for AD conversion
  ucADC_Data=ADC_convRead_uiData(AD0);//digitize signal(12-bit) at AD0 
*/


#include "derivative.h"
#include <stdtypes.h>
//#define ADC_TimeOut =TimerFlag[1]
//#define ADC_WaitTime =TimerTable[1]

Byte bADC_Sample=FALSE;

//--------------------------------------------------------
void ADC_Base_init(void){ //Turn on ADC module
  ADCSC1_AIEN=0;  //0=Disable ADC interrupt
  ADCSC1_ADCO=0;  //0=Single coversion
  //ADCSC1_ADCH=0b00000;  //0b00000=turn on ch 0 (0x1F=turn off) 
  
  ADCSC2_ADTRG=0; //0=Software triggered
  ADCSC2_ACFE=0;  //0=Compare function disabled
  ADCSC2_ACFGT=0; //Don't care:0=Compare triggers when input<compare level
  
  ADCCFG_ADLPC=1; //1=Low power configuration
  ADCCFG_ADIV=0b00; //0b00=input clock divide by 1
  ADCCFG_ADLSMP=1;  //1=set to long sample time and save power
  ADCCFG_MODE=0b00; //0b00=8-bit conversion
  ADCCFG_ADICLK=0b00; //0b00=use Bus clock 
 }
//--------------------------------------------------------
void ADC_turnOff(void){ //Turn off ADC module
  ADCSC1_ADCH=0b11111;  //0b11111=turn off ADC module 
}
//--------------------------------------------------------
void ADC_connectCh(unsigned char ucUsrChNo){//Connect pin for AD conversion
  switch (ucUsrChNo){
    case 0:
      APCTL1_ADPC0=1;  //1=disable I/O control, use as analog i/p AD0
      break;
    case 1:
      APCTL1_ADPC1=1;  //1=disable I/O control, use as analog i/p AD1
      break;
    case 2:
      APCTL1_ADPC2=1;  //1=disable I/O control, use as analog i/p AD2
      break;
    case 3:
      APCTL1_ADPC3=1;  //1=disable I/O control, use as analog i/p AD3
      break;
    case 4:
      APCTL1_ADPC4=1;  //1=disable I/O control, use as analog i/p AD4
      break;
    case 5:
      APCTL1_ADPC5=1;  //1=disable I/O control, use as analog i/p AD5
      break;
    case 6:
      APCTL1_ADPC6=1;  //1=disable I/O control, use as analog i/p AD6
      break;
    case 7:
      APCTL1_ADPC7=1;  //1=disable I/O control, use as analog i/p AD7
      break; 

  }
}

//--------------------------------------------------------
unsigned int ADC_convRead_uiData(unsigned char ucUsrChNo){//0..23 chs;12-bit data
  ADCSC1_ADCH= ucUsrChNo;  //start converting user channel 
  //ADC_TimeOut = FALSE;
  //ADC_WaitTime = 20;
  
  while (!ADCSC1_COCO /*&& !ADC_TimeOut*/);//wait for end of conversion
  //if (!ADC_TimeOut){
  //  ADC_WaitTime = 0;
    return ADCR;  //Return Read data
 // }else return 0xFFFF;
}


//---Alternative functions for connecting the ADC to analog input------
void ADC_setUp_Ch0(void){ //Setup Channel0 for ADC conversion
   
} //--------------------------------------------------------
void ADC_setUp_Ch1(void){ //Setup Channel1 for ADC conversion
  APCTL1_ADPC1=1;  //1=disable AD1 pin I/O control 
}//--------------------------------------------------------
void ADC_setUp_Ch2(void){ //Setup Channel2 for ADC conversion
  APCTL1_ADPC2=1;  //1=disable AD1 pin I/O control 
}//--------------------------------------------------------
void ADC_setUp_Ch3(void){ //Setup Channel3 for ADC conversion
  APCTL1_ADPC3=1;  //1=disable AD1 pin I/O control 
}//--------------------------------------------------------
void ADC_setUp_Ch4(void){ //Setup Channel4 for ADC conversion
  APCTL1_ADPC4=1;  //1=disable AD1 pin I/O control 
}//--------------------------------------------------------
void ADC_setUp_Ch5(void){ //Setup Channel5 for ADC conversion
  APCTL1_ADPC5=1;  //1=disable AD1 pin I/O control 
}//--------------------------------------------------------
void ADC_setUp_Ch6(void){ //Setup Channel6 for ADC conversion
  APCTL1_ADPC6=1;  //1=disable AD1 pin I/O control 
}//--------------------------------------------------------
void ADC_setUp_Ch7(void){ //Setup Channel7 for ADC conversion
  APCTL1_ADPC7=1;  //1=disable AD1 pin I/O control 
}
