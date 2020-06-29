/*Perpetual Calendar Routine
Leap Year Flag Conditions:

CONDITION 1: (divisible by 4 not by 100)
A year will be a leap year if it is divisible by 4 but not by 100. 
If a year is divisible by 4 and by 100, it is not a leap year unless it is also divisible by 400.

CONDITION 2: (divisible by 4, and by 100, and by 400)
Thus years such as 1996, 1992, 1988 and so on are leap years because 
they are divisible by 4 but not by 100. For century years, the 400 rule is important. 


Thus, century years 1900, 1800 and 1700 while all still divisible by 4 are also exactly 
divisible by 100. As they are not further divisible by 400, they are not leap years. 

Monthly Day-limits (include leap year consideration for Feb)
Jan_Days 31 
Feb_Days 28
Feb_Days_LEAP 29
Mar_Days 31
Apr_Days 30
May_Days 31
Jun_Days 30
Jul_Days 31
Aug_Days 31
Sep_Days 30
Oct_Days 31
Nov_Days 30
Dec_Days 31

authored 17 Nov 2008
*/

#include "derivative.h"
#include <MC9S08LC60.h>
#include "RTC.h"
#include <hidef.h>
#include "Calendar.h"
#include <stdio.h>
  
  
  extern unsigned int uiMonth; //factory default as november (11th month)
  extern unsigned int uiYear; //factory default as year 2008
  extern unsigned int uiDate; //factory default date 17th




 
void Calendar_Update (void) 
 {     
  
  unsigned int uiMaxDays;
  extern unsigned int uiLeapFlag; 
  
  if(uiMonth == 1) uiMaxDays = 31;   //31 for detection (jan) (31st jan is still valid date) 
 if(uiMonth == 2) uiMaxDays = 28;   //28 for detection (feb)
 if(uiMonth == 3) uiMaxDays = 31;   //31 for detection (mar)
 if(uiMonth == 4) uiMaxDays = 30;   //30 for detection (apr)
 if(uiMonth == 5) uiMaxDays = 31;   //31 for detection (may)
 if(uiMonth == 6) uiMaxDays = 30;   //30 for detection (jun)
 if(uiMonth == 7) uiMaxDays = 31;   //31 for detection (jul)
 if(uiMonth == 8) uiMaxDays = 31;   //31 for detection (aug)
 if(uiMonth == 9) uiMaxDays = 30;   //30 for detection (sep)
 if(uiMonth == 10) uiMaxDays = 31;  //31 for detection (oct)
 if(uiMonth == 11) uiMaxDays = 30;  //30 for detecttion (nov)
 if(uiMonth == 12) uiMaxDays = 31; //31 for detection (dec)
 if(uiMonth == 13) uiMaxDays = 29;  //29 for leap year feb case                                                                                                           
 
 //LEAP YEAR FEBRUARY CONDITION, ENTERING & EXITING LEAP YR FEBRUARIES
   if (((uiLeapFlag==1) && (uiMonth==1)) && (uiDate >= uiMaxDays))
     {
        uiMonth = 13;             // remaining in leap year february
        uiDate =1;
     }
   if((uiDate >= uiMaxDays)&&(uiMonth==13))   // exiting leap year february into 1st march (case 3)
     {
        uiDate = 1;            // reset to first day of following month
        uiMonth = 3;           // following month is march (exiting from a leap february)
     }//end if(uiDate == uiMaxDays)
        
      
                 

//NORMAL MONTHS & NON-LEAP YEAR FEBRUARIES  
  else
     {
       if(uiDate >= uiMaxDays)   //in the event of date > max days, correct this error
        {
          uiDate = 1;            // reset to first day of following month
         
         if(uiMonth == 12)       // end of year reached, reset to 1st day of following year (restarts months to jan)
          {
            uiDate = 1;
            uiMonth = 1;         // reset to first day of following year
            uiYear++;            // add 1 sequentially since end of december is reached
           
            //Test for Leap Year to set flags
            if(((uiYear%4)==0)&&((uiYear%100)!=0)){
             uiLeapFlag = 1;
            } else if((uiYear%4==0)&&(uiYear%100==0)&&(uiYear%400)){
             uiLeapFlag = 1;
            } else {
             uiLeapFlag = 0;
            } //end test for leap year
            
           
          
          }//end if(uiMonth==12)
         
         else //else (uiMonth!=12)
          {
            uiMonth++;           // add 1 to month for current year, end of year not reached
          }//end else (uiMonth!=12)
          
        }//end if(uiDate == uiMaxDays)
        
       else //end else(uiDate!=uiMaxDays)
        {
          uiDate++;              // add 1 to date for current month, end of month not reached 
        }//end else(uiDate!=uiMaxDays)
     }// end else (normal year, non-february months, no need to consider leap flag)
   
       
 }//end fn. calendar
  
 