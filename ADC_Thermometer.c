/*ADC_Thermometer.c

USER INSTRUCTIONS
-Connect heart rate sensor external module to the LC60 Home
Healthcare platform. 
-Press 3 to start temperature measurement in bpm
-Place finger above LED and keep still, wait for reading to stabilise (~12s)
-Read measurement display off the LCD on the LC60 platform

Developer Instructions
-Connect thermometer sensor ext. module to LC60 Home Healthcare 
platform (CONNECT TO PTC7) 
-Enter sensor module routine when keypress '3'
-Provide user feedback message to show start of application
-Provide user feedback (tone) to show completion of temperature measurement

**IMPORTANT NOTE: MUST FACTORY CALIBRATE TEMPERATURE PLATFORM BEFORE ALLOWING 
TEMPERATURE MODULE TO BE IN PRODUCTION FOR ACCURATE RESULTS
PLEASE SEE APPLICATION NOTES NEXT TO VARIABLES TO BE CHANGED 
FOR THIS CALIBRATION (refer to ADC calibration excel in developers documents). 

Connect all external devices to PTC7 (for 8 bit ADC with one free port) 
Date: 28 Dec 2008, David Wong Bingxiong
*/

#include <MC9S08LC60.h>
#include "derivative.h"
#include "ADC_Thermometer.h"
#include "Delays.h"
#include "ADC.h"
#include "Speaker.h"
#include "LCD_base.h"
#include "Timeout.h"
#include "KBI.h"
#include "LCD_base.h"
#include "Conversions.h"

void ADC_Temperature(void){
  
  unsigned int uiTempData;        // declaring variables
  TimeOut_stop();                 // stop time out counter to allow user to use thermometer application
  ADC_Base_init();                // turn on ADC module
  LCD_clrScreen();                // clear LCD of any exiting display
  LCD_putString("temp",0);        // user feedback that weight application has started
  delay100us(10000);              // short delay to display thermometer application message
  LCD_clrScreen();                // clear LCD screen of message
  
  ADC_connectCh(AD7);             // activate ADC pin 7 for temperature reading
  
  for(;;){
  uiTempData = ADC_convRead_uiData(7);// start conversion of ADC input from temperature sensor (hardware summed and averaged)
  //convert ATD reading to voltage
  //convert voltage calculation to degrees C
  //display
  }
}//end routine