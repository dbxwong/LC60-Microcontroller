/*ADC_Thermometer.h

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
FOR THIS CALIBRATION. 

Connect all external devices to PTC7 (for 8 bit ADC with one free port) 
Date: 28 Dec 2008, David Wong Bingxiong
*/


void ADC_Temperature(void);