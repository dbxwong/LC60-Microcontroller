/*ADC_BPM.c


USER INSTRUCTIONS
-Connect heart rate sensor external module to the LC60 Home
Healthcare platform. 
-Press A to start heart rate measurement in bpm
-Place finger above LED and keep still, wait for reading to stabilise (~12s)
-Read measurement display off the LCD on the LC60 platform

Developer Instructions
-Connect heart rate sensor ext. module to LC60 Home Healthcare 
platform (CONNECT TO PTC7) 
-Enter weight sensor module routine when keypress '1'
-Provide user feedback message to show start of application
-
-Provide user feedback (tone) to show completion of heart rate measurement
-imperial and metric options (for further development)                                    

-Optional exploration: Light up an LED for each heart beat detected

**IMPORTANT NOTE: MUST FACTORY CALIBRATE HEART RATE PLATFORM BEFORE ALLOWING 
HEART RATE MODULE TO BE IN PRODUCTION FOR ACCURATE RESULTS
PLEASE SEE APPLICATION NOTES NEXT TO VARIABLES TO BE CHANGED 
FOR THIS CALIBRATION. THIS SOFTWARE IS DESIGNED TO BE ALTERED
TO COMPENSATE FOR STRAIN GAUGE ZEROING ERRORS

Connect all external devices to PTC7 (for 8 bit ADC with one free port) 
Date: 27 Dec 2008, David Wong Bingxiong
*/

#include <MC9S08LC60.h>
#include "derivative.h"
#include "LEDs.h"
#include "ADC_WeightSensorModule.h"
#include "Delays.h"
#include "ADC.h"
#include "Speaker.h"
#include "LCD_base.h"
#include "KBI.h"
#include "LCD_base.h"
#include "Conversions.h" 
#include "Timeout.h"
#include "i2c_ver2.h"

unsigned int uiBeatCount=0, uiHR=0, uiBPM_ArrayIndex=0, uiBPM_MaxValue=0, BPM_peakValueIndex=0;
unsigned int auiBPM_Array[128], auiBPM_peakValues[6];
unsigned char aucBPMdisplayString[3];
extern unsigned char ucKey_press;
extern byte bADC_Sample;
extern unsigned int uiTimeCount;
//extern unsigned int uiData; 
extern unsigned char ucBPMTimeOutOccurred;

void ADC_HeartRate3(void){
  KBI1SC_KBACK = 1;               //Clear KBI interrupt
  TimeOut_stop();                 // stop time out counter to allow user to use weight application
  ADC_Base_init();                // turn on ADC module
  LCD_clrScreen();                // clear LCD of any exiting display
  //LCD_putString("BPM",0);         // user feedback that weight application has started
  //delay100us(50);              // short delay to display weight application message
  LCD_clrScreen();                // clear LCD screen of message
  ADC_connectCh(AD7);             // activate ADC pin 7 for weight reading
  
   
    for(uiBPM_ArrayIndex=0; uiBPM_ArrayIndex<=128; uiBPM_ArrayIndex++)
    {
      auiBPM_Array[uiBPM_ArrayIndex] = ADC_convRead_uiData(7); // start conversion of ADC into BPM array of 128
        
        if((auiBPM_Array[uiBPM_ArrayIndex] > auiBPM_Array[uiBPM_ArrayIndex-1]) && (auiBPM_Array[uiBPM_ArrayIndex] > auiBPM_Array[uiBPM_ArrayIndex-2]) && (auiBPM_Array[uiBPM_ArrayIndex] > auiBPM_Array[uiBPM_ArrayIndex-3])) 
        {       
          uiBPM_MaxValue = auiBPM_Array [uiBPM_ArrayIndex]; // max peak value update after upslope detector 
        }//end if: upslope-max peak value detector
       
        else if((auiBPM_Array[uiBPM_ArrayIndex] < auiBPM_Array[uiBPM_ArrayIndex-1]) && (auiBPM_Array[uiBPM_ArrayIndex] < auiBPM_Array[uiBPM_ArrayIndex-2]) && (auiBPM_Array[uiBPM_ArrayIndex] < auiBPM_Array[uiBPM_ArrayIndex-3]) && (uiBPM_MaxValue>=75))
        {
          uiBeatCount++; // add one to beat count once max peak value- down slope detected          
          
          
          
          
          
          
          /*uiHR = uiBeatCount * 10;
          LCD_putString("BPM",5);
          itoa(uiHR, &aucBPMdisplayString[3]);
          LCD_putString(aucBPMdisplayString,0);          
          uiBeatCount=0;                 // reset HR value
          uiHR=0;                        // reset HR value */ 
          
        }//end if max peak value-downslope detector
        
    }//end count-up for loop     



}//end ADC_HeartRate3




/*void ADC_HeartRate2(void){
 // LED5_turnOn();
  TimeOut_stop();                 // stop time out counter to allow user to use weight application
  ADC_Base_init();                // turn on ADC module
  BPM_TimeOut_init();
  LCD_clrScreen();                // clear LCD of any exiting display
  LCD_putString("BPM",0);         // user feedback that weight application has started
  delay100us(10000);              // short delay to display weight application message
  LCD_clrScreen();                // clear LCD screen of message
  ADC_connectCh(AD7);             // activate ADC pin 7 for weight reading
  uiBeatCount=0;  
    for(;;){
      
    if(ucBPMTimeOutOccurred==0){
    
      uiData2 = ADC_convRead_uiData(7);// start conversion of ADC input from weight sensors (hardware summed and averaged) 

      //OPTIONAL PROGRAM for other ADC to DAC conversion (build upon this framework for other health applications)
      if(bADC_Sample)
      { 
        ADC_connectCh(AD7);              //Connect pin for AD conversion
        uiData = ADC_convRead_uiData(7); //start converting user channel & read data when conv. finish
        IICDACwrite(0X98, uiData);       //send data to DAC (8bit Conversion)
      }//endif         

           
         if(uiData2==237) {               // set tolerance
         uiBeatCount++;    
         }// end if
         }// end if
        
        
        if(ucBPMTimeOutOccurred==1)
          {
          ADC_turnOff();
          uiHR = uiBeatCount * 10;
          uiBeatCount=0;                 // reset HR value
          uiHR=0;                        // reset HR value  
          LED5_turnOff();
          BPM_TimeOut_init();            // restart 6s BPM measurement cycle
           }// end if 
     }}
    }// end for(;;)
    
}//end heart rate 2 routine */










/* DRAFT ROUTINES (UNUSED)
void ADC_HeartRate (void){
  unsigned int uitempData1=0, uitempData2=0, uitempData3=0, uiHR=0; 
  unsigned int uiData2=0, uiIndex=0, uiUpslopeFlag=0, uiDownslopeFlag=0, uiPeakFlag=0, uiMaxValue=0, ui80percentThreshold=0, uiBPMcount=0;            // initialize variables, z = calibration factor (to be determined)
  unsigned int auiBPMstore[3]={0,0,0};
  TimeOut_stop();                 // stop time out counter to allow user to use weight application
  ADC_Base_init();                // turn on ADC module
  LCD_clrScreen();                // clear LCD of any exiting display
  LCD_putString("BPM",0);         // user feedback that weight application has started
  delay100us(10000);              // short delay to display weight application message
  LCD_clrScreen();                // clear LCD screen of message
  ADC_connectCh(AD7);             // activate ADC pin 7 for weight reading
  
  for(;;){
    uiData2 = ADC_convRead_uiData(7);// start conversion of ADC input from weight sensors (hardware summed and averaged)
        for (uiIndex=0;uiIndex<=3;uiIndex++){
        uiData2 = auiBPMstore[uiIndex];
        if(uiIndex==3)uiIndex=0;     // reset index
        }
        
        uitempData1 = auiBPMstore[0];    // store as temp variables for comparison
        uitempData2 = auiBPMstore[1];    // store as temp variables for comparison
        uitempData3 = auiBPMstore[2];    // store as temp variables for comparison
        
        //===UPSLOPE DECTECTION==================
        if((uitempData1<uitempData2)&&(uitempData2<uitempData3)){      // upslope detection, set flag
          uiUpslopeFlag=1;
          uiPeakFlag=0;
          if(uitempData2<uitempData3)uiMaxValue = uitempData3;         // set new max value after comparison
          ui80percentThreshold = uiMaxValue * (80 / 100);              // calculate 80% threshold to avoid false peak detection
        }//endif
                
        //===DOWNSLOPE DECTECTION================
        if((uitempData1>uitempData2)&&(uitempData2>uitempData3)){     // upslope detection, set flag
          uiDownslopeFlag=1;
        }//endif
        else uiDownslopeFlag=0; uiUpslopeFlag=0;
        
        //===PEAK DETECTION======================
        if((uiDownslopeFlag==1) && (uiMaxValue>ui80percentThreshold)){
          uiPeakFlag=1;
          if(uiBPMcountFlag==1){
            uiBPMcount++;
          }
          
          if(uiBPMcountFlag==0){
           uiHR = uiBPMcount * 12; //12 x 5s measurements to get BPM reading
           uiBPMcount = 0;       //reset BPM counter
          }
          
          
        }//endif
                                                     
        //======================================
               
                
      
        
  }//end for(;;)
}//end routine



void bpmTimeCount(void){ 
   unsigned int uiTime=0;
   if(uiTime<20){  // 208 counts from timer 1 = 5s
    uiTime++;       // add 1 to time keeper
    uiBPMcountFlag =1;
   }
   
   if(uiTime==20){
   uiTime=0;        // reset clock
    uiBPMcountFlag=0;
    LED5_turnOn();
   }
}//end routine*/
