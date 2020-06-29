/* BMI_IMP.c contains the routines for BMI calculator function that will be 
incorporated into the LC60 platform in Imperial units (Pounds & Feet)

The purpose of BMI.c is to allow user to calculate their BMI and monitor their general
health status. It is a home-health application added on to the platform.
A user manual will be produced at a later stage to document the steps and below.

Program is entered from main by pressing Keypad '0' which then prompts 
use to enter weight. Once user has entered weight, a keybad 'B' is needed
to acknowledge the user input.

Next, user will be prompted to enter height. Similarly, pressing 'B' will 
acknowledge user input. Pressing 'A' clears the screen and data buffer, user will 
be brought back to the BMI program entry and prompted for weight and height again.
Keypad 'A' restarts the BMI program. 

Once both parameters (weight and height) have been input and user has pressed B after
entering height, the BMI routine enters the computation stage. The BMI result is displayed
on the LCD for a preset period of time, before displaying the health status of the user.

BMI<18    = Display "UNDERWEIGHT" on LCD
17<BMI<25 = Display "NORMAL" on LCD
BMI>25    = Display "OBESE" on LCD
 
BMI = (pounds * 703) / (inches * inches)

User is required to press '0' to exit routine, else the BMI result and health status will 
display for 15s before timeout and platform enters Stop3 power saving mode. 
*/

#include <MC9S08LC60.h>   /* include LC60DemoBrd declarations */
#include "derivative.h"   /* include peripheral declarations */
#include "LCD_base.h"     /* include LCD_base routine declarations */
#include "Delays.h"       /* include Delays routine declarations */
#include "KBI.h"          /* include Keyboard Interrupt routine declarations */
#include "LEDs.h"         /* include LEDs routine declarations */
#include <cstdio.h>        /* include standard i/o declarations */
#include "StopModes.h"    /* include stop mode declarations */
#include "Timeout.h"
#include <stdlib.h> 
#include <stdio.h>
#include <math.h>        
#include <limits.h>

extern unsigned char ucKey_press; 
unsigned int BMIvalue_final;
unsigned char HtStore[4]={0,0,0,0};
unsigned char WtStore[4]={0,0,0,0};

int HtFlag=0, WtFlag=0;  


///////////////////////////
// HEALTH STATUS DISPLAY //
///////////////////////////
void DisplayBMICategory(){

if(15<BMIvalue_final && BMIvalue_final<=19){
SlideString("UNDERWT");
}//endif(underwt) 

else if(20<=BMIvalue_final && BMIvalue_final<=25){
SlideString("NORMAL");
}//endelseif(normal)

else if(26<=BMIvalue_final && BMIvalue_final<=30){
SlideString("OVERWT");
}//endelseif(overwt) 

else if(30<=BMIvalue_final && BMIvalue_final<=40){
SlideString("OBESE");
}//endelseif(obese)

else if (BMIvalue_final>80 || BMIvalue_final< 10){
SlideString("ERROR IN DATA");
}//endelse
}//endDisplayBMICategoryFunction

////////////
// GET WT //
////////////    POUNDS

unsigned int Get_weight(){
  
  static unsigned int Wt,j;
  static unsigned int Wt2;
  static unsigned char new_ucKey_press;
  
  LCD_clrScreen();                  // clear LCD of any existing KBI input 
  LCD_putString("ENTER WT",0);      // display BMI application entry
  delay100us(9000);                 // short delay to display BMI application entry
  LCD_clrScreen();                  // clear screen of BMI appl. entry
  j=0;
  while (j<4){
    new_ucKey_press = KBI_Read2();
    if(new_ucKey_press!='B'){
        WtStore[j]= new_ucKey_press;
        j++;
    }//endif
    
    else{
    WtStore[j]=0;
    j=5;
    }//endelse
   }//endfor
  
  if(j==5){            // j==4 signifies end of wt data acquisition
  Wt=atoi(WtStore);    // convert wt data to int
  Wt2=Wt;
  WtFlag=1;            // set wt conversion complete
  }
  return Wt2;
}//endGet_weight


////////////
// GET HT //
////////////     INCHES
unsigned int Get_height(){
  
  static int k,Ht,Ht2; 
  
  static unsigned char new_ucKey_press;
  
  LCD_clrScreen();                  // clear LCD of any existing KBI input 
  LCD_putString("ENTER HT",0);      // display BMI ht prompt
  delay100us(9000);                 // short delay to display BMI application entry
  LCD_clrScreen();                  // clear screen of BMI appl. entry

  k=0;
    while (k<4){
    new_ucKey_press = KBI_Read2();
    if(new_ucKey_press!='B'){
        HtStore[k]= new_ucKey_press;
        k++;
    }//endif
    
    else{
    WtStore[k]=0;
    k=5;
    }//endelse
   }//endwhile
  
  if(k==5){            // j==4 signifies end of wt data acquisition
  Ht=atoi(HtStore);    // convert wt data to int
  Ht2=(Ht*Ht);
  HtFlag=1;            // set wt conversion complete
  }
  return Ht2;
}//endGet_height


//////////////
// BMI CALC //
//////////////

unsigned int calc_BMI(unsigned int weight,unsigned int height){

if ((HtFlag ==1)&&(WtFlag==1)){ // calc BMI value if inputs complete

BMIvalue_final=weight*703/height;

} 

else {
  LCD_clrScreen();             // clear LCD of any existing KBI input 
  LCD_putString("ERROR",0);    // Error msg if incomplete input
  delay100us(9000);            // short delay to display 
  LCD_clrScreen();             // clear screen
}
  
return BMIvalue_final; 
}


///////////////////
// MAIN BMI PROG //
///////////////////

unsigned long long BMI_start(void){
  int height, weight; //declarations
    
  LCD_clrScreen();             // clear LCD of any existing KBI input 
  LCD_putString("BMI",0);      // display BMI application entry
  delay100us(10000);            // short delay to display BMI application entry
  LCD_clrScreen();             // clear screen of BMI appl. entry

  weight = Get_weight();
  
    if(WtFlag==1){    //wait for user to get_weight, then get height
    height = Get_height();  
    }
        
return calc_BMI(weight,height);
    }
