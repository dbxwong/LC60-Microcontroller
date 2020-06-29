/*ADC_BPM.h


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

//void ADC_HeartRate (void);
//void ADC_HeartRate2(void);
void ADC_HeartRate3(void);
//void bpmTimeCount(void);