
#include <string.h>

void reverse(unsigned char ucUsrString[]){//reverse user string in place
    unsigned char c, i, j;

    for (i=0, j=strlen(ucUsrString)-1; i<j; i++, j--) {
        c=ucUsrString[i];
        ucUsrString[i]=ucUsrString[j];
        ucUsrString[j]=c;
    }
}


void itoa(int iUsrNum, unsigned char ucUsrString[]){//conv int to ASCII string [-32768..32767]
    unsigned char i=0; 
    int iSign;
    
    if (iUsrNum<0){
      iSign=-1; //sign is negative
      iUsrNum=-iUsrNum; //make iUsrNum positive   
    }else{
      iSign=0;
    }
    do{ //generate digits in reverse order
        ucUsrString[i++]=iUsrNum%10+'0';   /* get next digit */
    } while ((iUsrNum/=10)>0);     /* delete it */
    if (iSign<0)
        ucUsrString[i++]='-';
    ucUsrString[i]='\0';
    reverse(ucUsrString);
}
