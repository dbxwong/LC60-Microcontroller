/* BMI.c contains the routines for BMI calculator function that will be 
incorporated into the LC60 platform. 

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


void BMI_calc(void){

//BMI_value_int = uiWeightValue/((uiHeightValue)*(uiHeightValue))
}//end BMI_calc


void BMI_display(void){
 TimeOut_restart(); //continue TimeOut Downcount after BMI calc routines are complete
}//end BMI_displayvoid 



void BMI_start(void){

volatile int uiWeightValue=0,uiHeightValue=0;
extern unsigned char key_press;
unsigned char WtStore[3]={0,0,0},j=0;  //j is position of wt digit for storage in wtStore array
unsigned char HtStore[3]={0,0,0},k=0;
unsigned int temp_time=0;
extern char BMI_readFlag;
  
///////////////////////////
// ENTER & PROMPT FOR WT //
///////////////////////////
                       
LCD_clrScreen();             // clear LCD of any existing KBI input 
LCD_putString("BMI",0);      // display BMI application entry
delay100us(3000);            // short delay to display BMI application entry
LCD_clrScreen();             // clear screen of BMI appl. entry

LCD_putString("ENTER WT",0); // prompt user to enter weight
delay100us(3000);            // short delay to prompt
LCD_clrScreen();             // clear screen of prompt
key_press =0; //clear key_press buffer

// main menu
display_main();
if (key_press == '0' )menu1();            //ckp
if (key_press == '1')menu2();
  
  
int BMI(){
  weight=get_weight();
  height=get_hegiht():
  return calculat_BMI(weight, height);
}
for(j=0;j<4;j++){
  if(key_press!='B'){
    WtStore[j] = get_key_press();    // store key_press input into wt array
      
  } 
  else{
    Wistore[j]=0;
    j=0;                                       //ckp

  }//end else- this loop wait for user input, else j=0

}




////////////////////////////////////////////
//USER ACKNOWLEDGE WT INPUT w B, PROMPT HT//
////////////////////////////////////////////


if((key_press == 66)&&(k<=3)){   //keypress66(1)
  
  
  
  LCD_putString("ENTER HT",0); // prompt user to enter weight
  delay100us(3000);            // short delay to prompt
  LCD_clrScreen();             // clear screen of prompt
  key_press =0;                // reset key_press

      for(k=0;k<4;k++){
  
          if(key_press!=0){
            HtStore[k]=key_press;        //store key_press input into ht array
          }//endifk_press&&

          else{
            k=0;
          }
  
      }//endfor
     
        

      
      
      
      
      }//endif key_press66(1)


/////////////////////////////////////////
// USER PRESS B to call Calc. Function //
///////////////////////////////////////// 
if(key_press==66){  // keypress66(2)
    
  LCD_putString("CALC",0);     // prompt user to enter weight
  delay100us(3000);            // short delay to prompt
  LCD_clrScreen();             // clear screen of prompt
  BMI_calc();                  // start BMI calculation
  }    


}//end BMIstart


