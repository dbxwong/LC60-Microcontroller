/*ADC_WeightSensorModule.c

USER INSTRUCTIONS
-Connect weight sensor external module to the LC60 Home
Healthcare platform. 
-Press A to start weight measurement in kg
-stand on weighing platform until reading stabilizes (~6-10s)
-Read measurement display off the LCD on the LC60 platform

Developer Instructions
-Connect weight sensor ext. module to LC60 Home Healthcare 
platform (CONNECT TO PTC7)
-Set time out counter to 3 mins (in case user delays and in the event of
accidental activiation of weight sensing application) 
-Enter weight sensor module routine when keypress 'A'
-Provide user feedback message to show start of application
-Weight from 4 strain gauges are summed and averaged with 
external circuit op amps (hardware summing and averaging)
-Set tolerance for weight measurement signal variation (if N - (N-1) < 10, 
then set signal as final weight) 
-Provide user feedback (tone) to show completion of weight measurement
-imperial and metric options (for further development)                                    

-Optional exploration: Store weight value for BMI calculation

**IMPORTANT NOTE: MUST FACTORY CALIBRATE WEIGHT PLATFORM BEFORE ALLOWING 
WEIGHT SENSOR MODULE TO BE IN PRODUCTION FOR ACCURATE RESULTS
PLEASE SEE APPLICATION NOTES NEXT TO VARIABLES TO BE CHANGED 
FOR THIS CALIBRATION. THIS SOFTWARE IS DESIGNED TO BE ALTERED
TO COMPENSATE FOR STRAIN GAUGE ZEROING ERRORS

Connect all external devices to PTC7 (for 8 bit ADC with one free port)


*/

#include <MC9S08LC60.h>
#include "derivative.h"
#include "ADC_WeightSensorModule.h"
#include "Delays.h"
#include "ADC.h"
#include "Speaker.h"
#include "LCD_base.h"
#include "Timeout.h"
#include "KBI.h"
#include "LCD_base.h"
#include "Conversions.h"

unsigned int uiWtData;     // initialize variables
unsigned int uiWeight_ADC;

void ADC_WeightSensor_8bit(void){

  

  unsigned char ucWeightDataADC[2];  
  int z = 7;                      // calibration factor 
  TimeOut_stop();                 // stop time out counter to allow user to use weight application
  ADC_Base_init();                // turn on ADC module
  LCD_clrScreen();                // clear LCD of any exiting display
  LCD_putString("WEIGHT",0);      // user feedback that weight application has started
  delay100us(10000);              // short delay to display weight application message
  LCD_clrScreen();                // clear LCD screen of message
  
  ADC_connectCh(AD7);             // activate ADC pin 7 for weight reading
  
  for(;;){
  uiWtData = ADC_convRead_uiData(7);// start conversion of ADC input from weight sensors (hardware summed and averaged)
  uiWeight_ADC = uiWtData/z;        // conversion of voltage from strain gauge circuit to kg by dividing by z (conversion factor ~7 see apps notes) 
  
  if (uiWeight_ADC > 10){         // when user starts applying weight on sensor (>10kg)
    //TimeOut_set(8000);            // gives user count 8000 (? s) to measure weight to prevent accidental activation
    itoa(uiWtData,&ucWeightDataADC[2]);     //fr hex to dec     
    LCD_putString(ucWeightDataADC,0);   //print screen
  }//end uiWeightADC>10
  }
}//end routine
  




/*void ADC_WeightSensor_StoreAvged(void){//enhanced program with internal averaging routine 
 
  unsigned int uiWeight_ADC=0, uiTotalWeight=0, uiAvgWeight=0, uiSample[10];
  unsigned char ucWeightDataADC[3]; 
  int i;
  int z = 7;                      // calibration factor 
  TimeOut_stop();                 // stop time out counter to allow user to use weight application
  ADC_Base_init();                // turn on ADC module
  LCD_clrScreen();                // clear LCD of any exiting display
  LCD_putString("WEIGHT",0);      // user feedback that weight application has started
  delay100us(9990);               // short delay to display weight application message    
  LCD_clrScreen();                // clear LCD screen of message
  ADC_connectCh(AD7);             // activate ADC pin 7 for weight reading


  uiData = ADC_convRead_uiData(7);// start conversion of ADC input from weight sensors (hardware summed and averaged)
  
  uiWeight_ADC = uiData/z;        // conversion of voltage from strain gauge circuit to kg by dividing by z (conversion factor ~7 see apps notes) 
  
  if (uiWeight_ADC > 10){         // when user starts applying weight on sensor (>10kg)
    TimeOut_set(9999);            // gives user count 8000 (? s) to measure weight to prevent accidental activation   
      for(i=0; i<10; i++) 
      {
        uiTotalWeight = uiAvgWeight + uiSample[i];   
      }
        uiAvgWeight = uiTotalWeight/10;     

    
  }//end uiWeightADC>10
}//end routine*/
