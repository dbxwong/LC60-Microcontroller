/////////////////////////////////////////////////////////////////////////////////////////
//
// LCD Library for Freescale DEMO9S08LC60
//
// S-TEK Display (model GD-3980)
// Driving Voltage: 3V
// Duty: 1/4
// Bias: 1/3
// Frequency: 64Hz
//
// --------------------------------------------------------------------------------------
//
// CodeWarrior V5.1 for HC(S)08
// Registers Files version 2.87.175
//
// --------------------------------------------------------------------------------------
//
// Copyright (c) 2006 SofTec Microsystems
// http://www.softecmicro.com/
//
/////////////////////////////////////////////////////////////////////////////////////////

#include "derivative.h"
#include "lcd.h"

/////////////////////////////////////////////////////////////////////////////////////////
// Variables
/////////////////////////////////////////////////////////////////////////////////////////

const struct lcd_char_segs lcd_char_table[] = {

  // ' ' (Space)
  {
  LCD_SEG_NONE,
  LCD_SEG_NONE,
  LCD_SEG_NONE,
  LCD_SEG_NONE
  },

  // '"' (Quotation Mark)
  {
  LCD_SEG_F,
  LCD_SEG_NONE,
  LCD_SEG_NONE,
  LCD_SEG_B
  },

  // ''' (Apostrophe)
  {
  LCD_SEG_NONE,
  LCD_SEG_NONE,
  LCD_SEG_NONE,
  LCD_SEG_J
  },

  // '(' (Left Parenthesis)
  {
  LCD_SEG_NONE,
  LCD_SEG_NONE,
  LCD_SEG_NONE ,
  LCD_SEG_K | LCD_SEG_N
  },

  // ')' (Right Parenthesis)
  {
  LCD_SEG_NONE | LCD_SEG_NONE,
  LCD_SEG_H | LCD_SEG_Q,
  LCD_SEG_NONE,
  LCD_SEG_NONE
  },

  // '*' (Asterisk)
  {
  LCD_SEG_NONE,
  LCD_SEG_H | LCD_SEG_G | LCD_SEG_Q | LCD_SEG_P,
  LCD_SEG_NONE, 
  LCD_SEG_J | LCD_SEG_K | LCD_SEG_M | LCD_SEG_N
  },

  // '+' (Plus Sign)
  {
  LCD_SEG_NONE,
  LCD_SEG_G | LCD_SEG_P,
  LCD_SEG_NONE,
  LCD_SEG_J | LCD_SEG_M
  },

  // ',' (Comma)
  {
  LCD_SEG_NONE,
  LCD_SEG_Q,
  LCD_SEG_NONE,
  LCD_SEG_NONE
  },

  // '-' (Minus Sign)
  {
  LCD_SEG_NONE,
  LCD_SEG_G,
  LCD_SEG_NONE,
  LCD_SEG_M
  },

  // '/' (Slash)
  {
  LCD_SEG_NONE,
  LCD_SEG_Q,
  LCD_SEG_NONE,
	LCD_SEG_K
  },

  // '0'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_NONE,
  LCD_SEG_D | LCD_SEG_A,
  LCD_SEG_B | LCD_SEG_C
  },

  // '1'
  {
  LCD_SEG_NONE,
  LCD_SEG_NONE,
  LCD_SEG_NONE,
  LCD_SEG_B | LCD_SEG_C | LCD_SEG_K
  },

  // '2'
  {
  LCD_SEG_E,
  LCD_SEG_G,
  LCD_SEG_D | LCD_SEG_A,
  LCD_SEG_B | LCD_SEG_M
  },

  // '3'
  {
  LCD_SEG_NONE,
  LCD_SEG_G,
  LCD_SEG_D | LCD_SEG_A,
  LCD_SEG_B | LCD_SEG_C | LCD_SEG_M
  },

  // '4'
  {
  LCD_SEG_F,
  LCD_SEG_G | LCD_SEG_P, 
  LCD_SEG_NONE,
  LCD_SEG_J | LCD_SEG_M
  },

  // '5'
  {
  LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_C | LCD_SEG_M
  },

  // '6'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_C | LCD_SEG_M
  },

  // '7'
  {
  LCD_SEG_NONE,
  LCD_SEG_NONE,
  LCD_SEG_A,
  LCD_SEG_B | LCD_SEG_C
  },

  // '8'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_B | LCD_SEG_C | LCD_SEG_M
  },

  // '9'
  {
  LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_A,
  LCD_SEG_B | LCD_SEG_C | LCD_SEG_M
  },

  // '=' (Equal Sign)
  {
  LCD_SEG_NONE,
  LCD_SEG_G,
  LCD_SEG_D,
  LCD_SEG_M
  },

  // 'A'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_A,
  LCD_SEG_B | LCD_SEG_C | LCD_SEG_M  
  },

  // 'B'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_K | LCD_SEG_N
  },

  // 'C'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_NONE,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_NONE
  },

  // 'D'
  {
  LCD_SEG_NONE,
  LCD_SEG_P,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_J | LCD_SEG_B | LCD_SEG_C  
  },

  // 'E'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_M
  },

  // 'F'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_A,
  LCD_SEG_M
  },

  // 'G'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_NONE,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_M | LCD_SEG_C
  },

  // 'H'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_NONE,
  LCD_SEG_M | LCD_SEG_B | LCD_SEG_C
  },

  // 'I'
  {
  LCD_SEG_NONE,
  LCD_SEG_P, 
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_J
  },

  // 'J'
  {
  LCD_SEG_E,
  LCD_SEG_NONE,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_B | LCD_SEG_C 
  },
  
  // 'K'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_NONE,             
  LCD_SEG_K | LCD_SEG_N
  },

  // 'L'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_NONE,
  LCD_SEG_D,
  LCD_SEG_NONE
  },

  // 'M'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_H,
  LCD_SEG_NONE,
  LCD_SEG_K | LCD_SEG_B | LCD_SEG_C
  },

  // 'N'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_H,
  LCD_SEG_NONE,  
  LCD_SEG_N | LCD_SEG_B | LCD_SEG_C
  },

  // 'O'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_NONE,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_B | LCD_SEG_C 
  },

  // 'P'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_A,
  LCD_SEG_B | LCD_SEG_M
  },

  // 'Q'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_NONE,
  LCD_SEG_A| LCD_SEG_D,
  LCD_SEG_N | LCD_SEG_B | LCD_SEG_C 
  },

  // 'R'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_NONE,
  LCD_SEG_A,
  LCD_SEG_M | LCD_SEG_N | LCD_SEG_B
  },

  // 'S'
  {
  LCD_SEG_F,
  LCD_SEG_G,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_M | LCD_SEG_C
  },

  // 'T'
  {
  LCD_SEG_NONE,
  LCD_SEG_P,
  LCD_SEG_A,
  LCD_SEG_J
  },

  // 'U'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_NONE,
  LCD_SEG_D,
  LCD_SEG_B | LCD_SEG_C
  },

  // 'V'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_Q,
  LCD_SEG_NONE,
  LCD_SEG_K
  },

  // 'W'
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_Q,
  LCD_SEG_NONE,
  LCD_SEG_B | LCD_SEG_C | LCD_SEG_N
  },

  // 'X'
  {
  LCD_SEG_NONE, 
  LCD_SEG_H | LCD_SEG_Q,
  LCD_SEG_NONE,
  LCD_SEG_K | LCD_SEG_N
  },

  // 'Y'
  {
  LCD_SEG_NONE,
  LCD_SEG_H | LCD_SEG_P,
  LCD_SEG_NONE,
  LCD_SEG_K
  },

  // 'Z'
  {
  LCD_SEG_NONE,
  LCD_SEG_Q,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_K
  },

  // '\' (Backslash)
  {
  LCD_SEG_NONE,
  LCD_SEG_H,
  LCD_SEG_NONE,
  LCD_SEG_N
  },

  // '_' (Underline)
  {
  LCD_SEG_NONE,
  LCD_SEG_NONE,
  LCD_SEG_D,
  LCD_SEG_NONE
  },

  // '|' (Vertical Bar)
  {
  LCD_SEG_NONE,
  LCD_SEG_P,
  LCD_SEG_NONE,
  LCD_SEG_J
  },

  // Test
  {
  LCD_SEG_E | LCD_SEG_F,
  LCD_SEG_H | LCD_SEG_G | LCD_SEG_Q | LCD_SEG_P,
  LCD_SEG_A | LCD_SEG_D,
  LCD_SEG_B | LCD_SEG_C | LCD_SEG_J | LCD_SEG_K | LCD_SEG_M | LCD_SEG_N
  }
  
};

/////////////////////////////////////////////////////////////////////////////////////////
// LCDInit
// --------------------------------------------------------------------------------------
// LCD Peripheral Initialization
/////////////////////////////////////////////////////////////////////////////////////////
void LCDInit(void)
{ 
 
  #if !CLOCK 
  // Select External Crystal clock (32.768 KHz) as LCD Clock Source. LCDCLK=32.768 KHz
  LCDCLKS = 0x00;
  
  #else
  // Select fBUS (8MHz) as LCD Clock Source. Enable prescaler by 16 and CLKADJ=14.
  // LCDCLK about 32.768 KHz
  LCDCLKS = 0xCE;
  
  #endif
    
  // Disable LCD frame frequency interrupt and configure LCD Module to continue running
  // during wait and stop3 mode
  LCDCR1 = 0x00;
  
  // Configures 1/4 duty cycle and 128 as LCD clock input divider (LCLK=3)
  // LCD Waveform Base Clock = 256 Hz
  LCDCR0 = 0x1B;
  
  //Enable charge pump (The internal 1/3-bias is forced)
  LCDSUPPLY |= 0x80;
  
  //Configures 2 Hz as LCD blink frequency (blink only individual LCD segments)
  LCDBCTL = 0x02;

  //Enable the LCD module frontplane waveform output (FP[39:0])
  FPENR0 = 0xFF;
  FPENR1 = 0xFF;
  FPENR2 = 0xFF;
  FPENR3 = 0xFF;
  FPENR4 = 0xFF;
    
  //Enables LCD driver module
  LCDCR0  |= 0x80;
    
}

/////////////////////////////////////////////////////////////////////////////////////////
// LCDBlinkState
// --------------------------------------------------------------------------------------
// Enable LCD Segments Blink State Mode
/////////////////////////////////////////////////////////////////////////////////////////
void LCDBlinkState(void)
{
  
  //Selects LCDRAM registers that control LCD segments blink state (LCDDRMS=1)
  LCDCMD = 0x08;
  
  //Starts LCD module blinking (BLINK=1)
  LCDBCTL |= 0x80;
  
}

/////////////////////////////////////////////////////////////////////////////////////////
// LCDOnOffState
// --------------------------------------------------------------------------------------
// Enable LCD Segments ON/OFF State Mode
/////////////////////////////////////////////////////////////////////////////////////////
void LCDOnOffState(void)
{

  //Stop LCD module blinking (BLINK=0)
  LCDBCTL &= ~0x80;
  
  //Selects LCDRAM registers that control LCD segments on/off state (LCDDRMS=0)
  LCDCMD = 0x00;

}

/////////////////////////////////////////////////////////////////////////////////////////
// LCDClear
// --------------------------------------------------------------------------------------
// Clear LCDRAM Registers
/////////////////////////////////////////////////////////////////////////////////////////
void LCDClear(void)
{

  //LCD Data Register Clear Command
  LCDCMD |= 0x02;
  //Wait until all bits in the LCDRAM registers are set to 0.
  while (LCDCMD &= 0x02)
    ;
    
}

/////////////////////////////////////////////////////////////////////////////////////////
// LCDFindChar
// --------------------------------------------------------------------------------------
// Finds the given character in the characters table
/////////////////////////////////////////////////////////////////////////////////////////
unsigned char LCDFindChar(unsigned char character)
{
  if(character == ' ')
    return(LCD_CHAR_SPACE);
  else if(character == '"')
    return(LCD_CHAR_QUOTMARK);
  else if(character >= '\'' && character <= '-')
    return(character - '\'' + LCD_CHAR_APOSTROPHE);
  else if(character == '/')
    return(LCD_CHAR_SLASH);
  else if(character >= '0' && character <= '9')
    return(character - '0' + LCD_CHAR_0);
  else if(character == '=')
    return(LCD_CHAR_EQUAL);
  else if(character >= 'A' && character <= 'Z')
    return(character - 'A' + LCD_CHAR_A);
  else if(character == '\\')
    return(LCD_CHAR_BACKSLASH);
  else if(character == '_')
    return(LCD_CHAR_UNDERLINE);
  else if(character >= 'a' && character <= 'z')
    return(character - 'a' + LCD_CHAR_A);
  else if(character == '|')
    return(LCD_CHAR_VERTBAR);
  else
    return(LCD_CHAR_TEST);
  
}

/////////////////////////////////////////////////////////////////////////////////////////
// LCDPutChar
// --------------------------------------------------------------------------------------
// Put Char in the LCDRAM Register
/////////////////////////////////////////////////////////////////////////////////////////
void LCDPutChar(unsigned char character, unsigned char digit)
{

  unsigned char *pLCDRAM0 = &LCDRAM0, table_pos;

  if(digit > NUM_DIGITS)
    return;
  
  digit=(digit-1)*2;  //Because digit starts from 1 and every display fills 2 byte
  
  table_pos = LCDFindChar(character);
      
  //Clears Segments E F 
  *(pLCDRAM0+LCDRAM_EF+digit) &= ~MASK_EF;
  //Writes Segments E F
  *(pLCDRAM0+LCDRAM_EF+digit) |= lcd_char_table[table_pos].EF;
  
  //Clears Segments P Q G H
  *(pLCDRAM0+LCDRAM_PQGH+digit) &= ~MASK_PQGH;
  //Writes Segments P Q G H
  *(pLCDRAM0+LCDRAM_PQGH+digit) |= lcd_char_table[table_pos].PQGH;
  
  //Clears Segments D C B A
  *(pLCDRAM0+LCDRAM_DCBA+digit) &= ~MASK_DCBA;
  //Writes Segments D C B A
  *(pLCDRAM0+LCDRAM_DCBA+digit) |= lcd_char_table[table_pos].DCBA;
  
  //Clears Segments N M K J 
  *(pLCDRAM0+LCDRAM_NMKJ+digit) &= ~MASK_NMKJ;
  //Writes Segments N M K J
  *(pLCDRAM0+LCDRAM_NMKJ+digit) |= lcd_char_table[table_pos].NMKJ;
 
}

/////////////////////////////////////////////////////////////////////////////////////////
// LCDWriteSegment
// --------------------------------------------------------------------------------------
// Enables Segment in the LCDRAM Register
/////////////////////////////////////////////////////////////////////////////////////////
void LCDWriteSegment(enum symbol s, unsigned char num)
{

  switch(s)
  {
  
    case TIME:
      LCDRAM1 |= LCDRAM1_FP2BP3_MASK;
      break;
    case DT:
      LCDRAM1 |= LCDRAM1_FP3BP3_MASK;
      break;
    case DATE:
      LCDRAM3 |= LCDRAM3_FP6BP3_MASK;
      break;
    case FREESCALE:
      LCDRAM5 |= LCDRAM5_FP10BP3_MASK;
      break;
    case FIRE:
      LCDRAM5 |= LCDRAM5_FP11BP3_MASK;
      break;
    case TEMP:
      LCDRAM7 |= LCDRAM7_FP14BP3_MASK;
      break;  
    case SNOWFLAKE:
      LCDRAM7 |= LCDRAM7_FP15BP3_MASK;
      break;
    case VOLUME:
      LCDRAM9 |= LCDRAM9_FP18BP3_MASK;
      break;
    case ALARM:
      LCDRAM11 |= LCDRAM11_FP22BP3_MASK;
      break;
    case T:
      LCDRAM11 |= LCDRAM11_FP23BP3_MASK;
      break;
    case P:
      LCDRAM13 |= LCDRAM13_FP26BP3_MASK;
      break;
    /*case CONTRAST:
      LCDRAM15 |= LCDRAM15_FP30BP3_MASK;
      break;
    case MODE:
      LCDRAM15 |= LCDRAM15_FP31BP3_MASK;
      break; */
      
      case CONTRAST:
      LCDRAM14 |= LCDRAM14_FP29BP3_MASK;
      LCDRAM14 |= LCDRAM14_FP29BP2_MASK;
      LCDRAM14 |= LCDRAM14_FP29BP1_MASK;
      LCDRAM14 |= LCDRAM14_FP29BP0_MASK;
      LCDRAM14 |= LCDRAM14_FP28BP3_MASK;
      LCDRAM14 |= LCDRAM14_FP28BP2_MASK;
      LCDRAM14 |= LCDRAM14_FP28BP1_MASK;
      LCDRAM14 |= LCDRAM14_FP28BP0_MASK;
      break;
      
      case MODE:
      LCDRAM15 |= LCDRAM15_FP31BP3_MASK;
      LCDRAM15 |= LCDRAM15_FP31BP2_MASK;
      LCDRAM15 |= LCDRAM15_FP31BP1_MASK;
      LCDRAM15 |= LCDRAM15_FP31BP0_MASK;
      LCDRAM15 |= LCDRAM15_FP30BP3_MASK;
      LCDRAM15 |= LCDRAM15_FP30BP2_MASK;
      LCDRAM15 |= LCDRAM15_FP30BP1_MASK;
      LCDRAM15 |= LCDRAM15_FP30BP0_MASK;
      break;
      
      case A:
      LCDRAM16 |= LCDRAM16_FP33BP3_MASK;
      LCDRAM16 |= LCDRAM16_FP33BP2_MASK;
      LCDRAM16 |= LCDRAM16_FP33BP1_MASK;
      LCDRAM16 |= LCDRAM16_FP33BP0_MASK;
      LCDRAM16 |= LCDRAM16_FP32BP3_MASK;
      LCDRAM16 |= LCDRAM16_FP32BP2_MASK;
      LCDRAM16 |= LCDRAM16_FP32BP1_MASK;
      LCDRAM16 |= LCDRAM16_FP32BP0_MASK;
      break;
      
      case B:
      LCDRAM17 |= LCDRAM17_FP35BP3_MASK;
      LCDRAM17 |= LCDRAM17_FP35BP2_MASK;
      LCDRAM17 |= LCDRAM17_FP35BP1_MASK;
      LCDRAM17 |= LCDRAM17_FP35BP0_MASK;
      LCDRAM17 |= LCDRAM17_FP34BP3_MASK;
      LCDRAM17 |= LCDRAM17_FP34BP2_MASK;
      LCDRAM17 |= LCDRAM17_FP34BP1_MASK;
      LCDRAM17 |= LCDRAM17_FP34BP0_MASK;
      break;
      
      
      
    case AM:
      LCDRAM18 |= LCDRAM18_FP36BP1_MASK;
      break;
    case PM:
      LCDRAM18 |= LCDRAM18_FP36BP2_MASK;
      break;
    case OM:
      LCDRAM18 |= LCDRAM18_FP36BP3_MASK;
      break;
    case KWH:
      LCDRAM18 |= LCDRAM18_FP37BP0_MASK;
      break;
    case AMPS:
      LCDRAM18 |= LCDRAM18_FP37BP1_MASK;
      break;
    case VOLTS:
      LCDRAM18 |= LCDRAM18_FP37BP2_MASK;
      break;
    case PROGRAM:
      LCDRAM18 |= LCDRAM18_FP37BP3_MASK;
      break;
    case VOL:
      LCDRAM19 |= LCDRAM19_FP38BP0_MASK;
      break;
      
    case DTx:
      switch(num)
      {
        case 1:
          LCDRAM1 |= LCDRAM1_FP3BP2_MASK;
          break;
        case 2:
          LCDRAM3 |= LCDRAM3_FP7BP3_MASK;
          break;        
        case 3:
          LCDRAM5 |= LCDRAM5_FP11BP2_MASK;
          break;         
        case 4:
          LCDRAM7 |= LCDRAM7_FP15BP2_MASK;
          break;        
        case 5:
          LCDRAM9 |= LCDRAM9_FP19BP3_MASK;
          break;        
        case 6:
          LCDRAM11 |= LCDRAM11_FP23BP2_MASK;
          break;        
        case 7:
          LCDRAM13 |= LCDRAM13_FP27BP3_MASK;
          break;        
        case 8:
          LCDRAM15 |= LCDRAM15_FP31BP2_MASK;
          break;        
        case 9:
          LCDRAM17 |= LCDRAM17_FP35BP2_MASK;
          break;        
      }
      break;
    case COLONx:
      switch(num)
      {
        case 1:
          LCDRAM3 |= LCDRAM3_FP7BP2_MASK;
          break;
        case 2:
          LCDRAM9 |= LCDRAM9_FP19BP2_MASK;
          break;        
        case 3:
          LCDRAM13 |= LCDRAM13_FP27BP2_MASK;
          break;         
        case 4:
          LCDRAM17 |= LCDRAM17_FP34BP3_MASK;
          break;               
      }
      break;
    case Vx:
      switch(num)
      {
        case 1:
          LCDRAM17 |= LCDRAM17_FP35BP3_MASK;
          break;
        case 2:
          LCDRAM18 |= LCDRAM18_FP36BP0_MASK;
          break;        
        case 3:
          LCDRAM19 |= LCDRAM19_FP38BP1_MASK;
          break;         
        case 4:
          LCDRAM19 |= LCDRAM19_FP38BP2_MASK;
          break;
        case 5:
          LCDRAM19 |= LCDRAM19_FP38BP3_MASK;
          break;                          
      }
      break;
    case Tx:
      switch(num)
      {
        case 1:
          LCDRAM19 |= LCDRAM19_FP39BP3_MASK;
          break;
        case 2:
          LCDRAM19 |= LCDRAM19_FP39BP2_MASK;
          break;        
        case 3:
          LCDRAM19 |= LCDRAM19_FP39BP1_MASK;
          break;         
        case 4:
          LCDRAM19 |= LCDRAM19_FP39BP0_MASK;
          break;                        
      }
      break;
  }
  
}

/////////////////////////////////////////////////////////////////////////////////////////
// LCDClearSegment
// --------------------------------------------------------------------------------------
// Disables Segment in the LCDRAM Register
/////////////////////////////////////////////////////////////////////////////////////////
void LCDClearSegment(enum symbol s, unsigned char num)
{

  switch(s)
  {
  
    case TIME:
      LCDRAM1 &= ~LCDRAM1_FP2BP3_MASK;
      break;
    case DT:
      LCDRAM1 &= ~LCDRAM1_FP3BP3_MASK;
      break;
    case DATE:
      LCDRAM3 &= ~LCDRAM3_FP6BP3_MASK;
      break;
    case FREESCALE:
      LCDRAM5 &= ~LCDRAM5_FP10BP3_MASK;
      break;
    case FIRE:
      LCDRAM5 &= ~LCDRAM5_FP11BP3_MASK;
      break;
    case TEMP:
      LCDRAM7 &= ~LCDRAM7_FP14BP3_MASK;
      break;  
    case SNOWFLAKE:
      LCDRAM7 &= ~LCDRAM7_FP15BP3_MASK;
      break;
    case VOLUME:
      LCDRAM9 &= ~LCDRAM9_FP18BP3_MASK;
      break;
    case ALARM:
      LCDRAM11 &= ~LCDRAM11_FP22BP3_MASK;
      break;
    case T:
      LCDRAM11 &= ~LCDRAM11_FP23BP3_MASK;
      break;
    case P:
      LCDRAM13 &= ~LCDRAM13_FP26BP3_MASK;
      break;
   /* case CONTRAST:
      LCDRAM15 &= ~LCDRAM15_FP30BP3_MASK;
      break;
    case MODE:
      LCDRAM15 &= ~LCDRAM15_FP31BP3_MASK;
      break; */
      
      case CONTRAST:
      LCDRAM14 &= ~LCDRAM14_FP29BP3_MASK;
      LCDRAM14 &= ~LCDRAM14_FP29BP2_MASK;
      LCDRAM14 &= ~LCDRAM14_FP29BP1_MASK;
      LCDRAM14 &= ~LCDRAM14_FP29BP0_MASK;
      LCDRAM14 &= ~LCDRAM14_FP28BP3_MASK;
      LCDRAM14 &= ~LCDRAM14_FP28BP2_MASK;
      LCDRAM14 &= ~LCDRAM14_FP28BP1_MASK;
      LCDRAM14 &= ~LCDRAM14_FP28BP0_MASK;
      break;
      
      case MODE:
      LCDRAM15 &= ~LCDRAM15_FP31BP3_MASK;
      LCDRAM15 &= ~LCDRAM15_FP31BP2_MASK;
      LCDRAM15 &= ~LCDRAM15_FP31BP1_MASK;
      LCDRAM15 &= ~LCDRAM15_FP31BP0_MASK;
      LCDRAM15 &= ~LCDRAM15_FP30BP3_MASK;
      LCDRAM15 &= ~LCDRAM15_FP30BP2_MASK;
      LCDRAM15 &= ~LCDRAM15_FP30BP1_MASK;
      LCDRAM15 &= ~LCDRAM15_FP30BP0_MASK;
      break;
      
      case A:
      LCDRAM16 &= ~LCDRAM16_FP33BP3_MASK;
      LCDRAM16 &= ~LCDRAM16_FP33BP2_MASK;
      LCDRAM16 &= ~LCDRAM16_FP33BP1_MASK;
      LCDRAM16 &= ~LCDRAM16_FP33BP0_MASK;
      LCDRAM16 &= ~LCDRAM16_FP32BP3_MASK;
      LCDRAM16 &= ~LCDRAM16_FP32BP2_MASK;
      LCDRAM16 &= ~LCDRAM16_FP32BP1_MASK;
      LCDRAM16 &= ~LCDRAM16_FP32BP0_MASK;
      break;
      
      case B:
      LCDRAM17 &= ~LCDRAM17_FP35BP3_MASK;
      LCDRAM17 &= ~LCDRAM17_FP35BP2_MASK;
      LCDRAM17 &= ~LCDRAM17_FP35BP1_MASK;
      LCDRAM17 &= ~LCDRAM17_FP35BP0_MASK;
      LCDRAM17 &= ~LCDRAM17_FP34BP3_MASK;
      LCDRAM17 &= ~LCDRAM17_FP34BP2_MASK;
      LCDRAM17 &= ~LCDRAM17_FP34BP1_MASK;
      LCDRAM17 &= ~LCDRAM17_FP34BP0_MASK;
      break;
      
    case AM:
      LCDRAM18 &= ~LCDRAM18_FP36BP1_MASK;
      break;
    case PM:
      LCDRAM18 &= ~LCDRAM18_FP36BP2_MASK;
      break;
    case OM:
      LCDRAM18 &= ~LCDRAM18_FP36BP3_MASK;
      break;
    case KWH:
      LCDRAM18 &= ~LCDRAM18_FP37BP0_MASK;
      break;
    case AMPS:
      LCDRAM18 &= ~LCDRAM18_FP37BP1_MASK;
      break;
    case VOLTS:
      LCDRAM18 &= ~LCDRAM18_FP37BP2_MASK;
      break;
    case PROGRAM:
      LCDRAM18 &= ~LCDRAM18_FP37BP3_MASK;
      break;
    case VOL:
      LCDRAM19 &= ~LCDRAM19_FP38BP0_MASK;
      break;
      
    case DTx:
      switch(num)
      {
        case 1:
          LCDRAM1 &= ~LCDRAM1_FP3BP2_MASK;
          break;
        case 2:
          LCDRAM3 &= ~LCDRAM3_FP7BP3_MASK;
          break;        
        case 3:
          LCDRAM5 &= ~LCDRAM5_FP11BP2_MASK;
          break;         
        case 4:
          LCDRAM7 &= ~LCDRAM7_FP15BP2_MASK;
          break;        
        case 5:
          LCDRAM9 &= ~LCDRAM9_FP19BP3_MASK;
          break;        
        case 6:
          LCDRAM11 &= ~LCDRAM11_FP23BP2_MASK;
          break;        
        case 7:
          LCDRAM13 &= ~LCDRAM13_FP27BP3_MASK;
          break;        
        case 8:
          LCDRAM15 &= ~LCDRAM15_FP31BP2_MASK;
          break;        
        case 9:
          LCDRAM17 &= ~LCDRAM17_FP35BP2_MASK;
          break;        
      }
      break;
    case COLONx:
      switch(num)
      {
        case 1:
          LCDRAM3 &= ~LCDRAM3_FP7BP2_MASK;
          break;
        case 2:
          LCDRAM9 &= ~LCDRAM9_FP19BP2_MASK;
          break;        
        case 3:
          LCDRAM13 &= ~LCDRAM13_FP27BP2_MASK;
          break;         
        case 4:
          LCDRAM17 &= ~LCDRAM17_FP34BP3_MASK;
          break;               
      }
      break;
    case Vx:
      switch(num)
      {
        case 1:
          LCDRAM17 &= ~LCDRAM17_FP35BP3_MASK;
          break;
        case 2:
          LCDRAM18 &= ~LCDRAM18_FP36BP0_MASK;
          break;        
        case 3:
          LCDRAM19 &= ~LCDRAM19_FP38BP1_MASK;
          break;         
        case 4:
          LCDRAM19 &= ~LCDRAM19_FP38BP2_MASK;
          break;
        case 5:
          LCDRAM19 &= ~LCDRAM19_FP38BP3_MASK;
          break;                          
      }
      break;
    case Tx:
      switch(num)
      {
        case 1:
          LCDRAM19 &= ~LCDRAM19_FP39BP3_MASK;
          break;
        case 2:
          LCDRAM19 &= ~LCDRAM19_FP39BP2_MASK;
          break;        
        case 3:
          LCDRAM19 &= ~LCDRAM19_FP39BP1_MASK;
          break;         
        case 4:
          LCDRAM19 &= ~LCDRAM19_FP39BP0_MASK;
          break;                        
      }
      break;
  }
  
}

/////////////////////////////////////////////////////////////////////////////////////////
// LCDTest
// --------------------------------------------------------------------------------------
// Enable all segments in the LCDRAM Register
/////////////////////////////////////////////////////////////////////////////////////////
void LCDTest (void)
{
  
  char i;
  
  LCDWriteSegment(TIME,0);
  LCDWriteSegment(DT,0);
  LCDWriteSegment(DATE,0);
  LCDWriteSegment(FREESCALE,0);
  LCDWriteSegment(FIRE,0);
  LCDWriteSegment(TEMP,0);
  LCDWriteSegment(SNOWFLAKE,0);
  LCDWriteSegment(VOLUME,0);
  LCDWriteSegment(ALARM,0);
  LCDWriteSegment(T,0);
  LCDWriteSegment(P,0);
  LCDWriteSegment(CONTRAST,0);
  LCDWriteSegment(MODE,0);
  LCDWriteSegment(A,0);
  LCDWriteSegment(B,0);
  LCDWriteSegment(AM,0);
  LCDWriteSegment(PM,0);
  LCDWriteSegment(OM,0);
  LCDWriteSegment(KWH,0);
  LCDWriteSegment(AMPS,0);
  LCDWriteSegment(VOLTS,0); 
  LCDWriteSegment(PROGRAM,0);
  LCDWriteSegment(VOL,0);
  for (i=1; i<10; i++) 
  { 
    LCDPutChar('?', i);
    LCDWriteSegment(DTx,i);
    if (i<6) 
    {
      LCDWriteSegment(Vx,i);
      if (i<5) 
      {
        LCDWriteSegment(COLONx,i);
        LCDWriteSegment(Tx,i);
      }
    }
  }  
       
}