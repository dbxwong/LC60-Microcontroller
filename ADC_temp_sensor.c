#include <MC9S08LC60.h>
#include "derivative.h"
#include "ADC_Thermometer.h"
#include "Delays.h"
#include "ADC.h"
#include "LCD_base.h"
#include "Timeout.h"
#include "KBI.h"
#include "LCD_base.h"
#include "Conversions.h"

int iVtemp=0;
float fTempC=0;
float fADC_temp_sensor_start(void){ //Turn on ADC module
 
 iVtemp = (int)ADC_convRead_uiData(26);
 
 fTempC = (float) (iVtemp - 0.7013) / (0.0017);
 
 return fTempC;
}//end temp_sensor_start
 