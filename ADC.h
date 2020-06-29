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
Ch  Name  Functions         80pins  J101  Device
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

#ifndef ADC_H 
#define ADC_H 
#define ADC_TimeOut TimerFlag[1]

enum ADCChAvailable {AD0,AD1,AD2,AD3,AD4,AD5,AD6,AD7};

void ADC_Base_init(void); //Turn on ADC module
void ADC_turnOff(void); //Turn off ADC module
void ADC_connectCh(unsigned char ucUsrChNo);//Connect pin for AD conversion
unsigned int ADC_convRead_uiData(unsigned char ucUsrChNo);//0..23 chs;12-bit data

//Alternative for connecting up the channels
void ADC_setUp_Ch0(void); //Setup Channel0 for ADC conversion
void ADC_setUp_Ch1(void); //Setup Channel1 for ADC conversion
void ADC_setUp_Ch2(void); //Setup Channel2 for ADC conversion
void ADC_setUp_Ch3(void); //Setup Channel3 for ADC conversion
void ADC_setUp_Ch4(void); //Setup Channel4 for ADC conversion
void ADC_setUp_Ch5(void); //Setup Channel5 for ADC conversion
void ADC_setUp_Ch6(void); //Setup Channel6 for ADC conversion
void ADC_setUp_Ch7(void); //Setup Channel7 for ADC conversion



#endif