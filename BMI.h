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

void BMI_start(void);
void BMI_calc(void);
void BMI_display(void);
void BMI_heightEntry(void);