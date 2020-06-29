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


#ifndef ADC_WEIGHTSENSORMODULE_H
#define ADC_WEIGHTSENSORMODULE_H

void ADC_WeightSensor_8bit(void); 
void ADC_WeightSensor_StoreAvged(void); 
#endif 


