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

/////////////////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////////////////

// Put CLOCK=0 for select FEE mode (external crystal = 32.768 KHz)
// Put CLOCK=1 for select FEI (internal clock = 243 KHz)
#define CLOCK                   1

#define LCD_CHAR_SPACE          0       // ' ' (Space)
#define LCD_CHAR_QUOTMARK       1       // '"' (Quotation Mark)
#define LCD_CHAR_APOSTROPHE     2       // ''' (Apostrophe)
#define LCD_CHAR_LPAREN         3       // '(' (Left Parenthesis)
#define LCD_CHAR_RPAREN         4       // ')' (Right Parenthesis)
#define LCD_CHAR_ASTERISK       5       // '*' (Asterisk)
#define LCD_CHAR_PLUS           6       // '+' (Plus Sign)
#define LCD_CHAR_COMMA          7       // ',' (Comma)
#define LCD_CHAR_MINUS          8       // '-' (Minus Sign)
#define LCD_CHAR_SLASH          9       // '/' (Slash)
#define LCD_CHAR_0              10      // '0'
#define LCD_CHAR_1              11      // '1'
#define LCD_CHAR_2              12      // '2'
#define LCD_CHAR_3              13      // '3'
#define LCD_CHAR_4              14      // '4'
#define LCD_CHAR_5              15      // '5'
#define LCD_CHAR_6              16      // '6'
#define LCD_CHAR_7              17      // '7'
#define LCD_CHAR_8              18      // '8'
#define LCD_CHAR_9              19      // '9'
#define LCD_CHAR_EQUAL          20      // '=' (Equal Sign)
#define LCD_CHAR_A              21      // 'A'
#define LCD_CHAR_B              22      // 'B'
#define LCD_CHAR_C              23      // 'C'
#define LCD_CHAR_D              24      // 'D'
#define LCD_CHAR_E              25      // 'E'
#define LCD_CHAR_F              26      // 'F'
#define LCD_CHAR_G              27      // 'G'
#define LCD_CHAR_H              28      // 'H'
#define LCD_CHAR_I              29      // 'I'
#define LCD_CHAR_J              30      // 'J'
#define LCD_CHAR_K              31      // 'K'
#define LCD_CHAR_L              32      // 'L'
#define LCD_CHAR_M              33      // 'M'
#define LCD_CHAR_N              34      // 'N'
#define LCD_CHAR_O              35      // 'O'
#define LCD_CHAR_P              36      // 'P'
#define LCD_CHAR_Q              37      // 'Q'
#define LCD_CHAR_R              38      // 'R'
#define LCD_CHAR_S              39      // 'S'
#define LCD_CHAR_T              40      // 'T'
#define LCD_CHAR_U              41      // 'U'
#define LCD_CHAR_V              42      // 'V'
#define LCD_CHAR_W              43      // 'W'
#define LCD_CHAR_X              44      // 'X'
#define LCD_CHAR_Y              45      // 'Y'
#define LCD_CHAR_Z              46      // 'Z'
#define LCD_CHAR_BACKSLASH      47      // '\' (Backslash)
#define LCD_CHAR_UNDERLINE      48      // '_' (Underline)
#define LCD_CHAR_VERTBAR        49      // '|' (Vertical Bar)
#define LCD_CHAR_TEST           50      // All segments on

#define LCD_SEG_NONE            0x00


#define LCD_SEG_E               0x02
#define LCD_SEG_F               0x04


#define LCD_SEG_P               0x10
#define LCD_SEG_Q               0x20
#define LCD_SEG_G               0x40
#define LCD_SEG_H               0x80

#define LCD_SEG_D               0x01
#define LCD_SEG_C               0x02
#define LCD_SEG_B               0x04
#define LCD_SEG_A               0x08

#define LCD_SEG_N               0x10
#define LCD_SEG_M               0x20
#define LCD_SEG_K               0x40
#define LCD_SEG_J               0x80


#define NUM_DIGITS              9
#define NUM_CHARS   			      sizeof(lcd_char_table)/sizeof(lcd_char_table[0])

#define MASK_EF                (LCD_SEG_E|LCD_SEG_F)
#define MASK_PQGH              (LCD_SEG_P|LCD_SEG_Q|LCD_SEG_G|LCD_SEG_H)
#define MASK_DCBA              (LCD_SEG_D|LCD_SEG_C|LCD_SEG_B|LCD_SEG_A)
#define MASK_NMKJ              (LCD_SEG_N|LCD_SEG_M|LCD_SEG_K|LCD_SEG_J)

#define LCDRAM_EF               0
#define LCDRAM_PQGH             0
#define LCDRAM_DCBA             1
#define LCDRAM_NMKJ             1

const struct lcd_char_segs {
  unsigned char EF;
  unsigned char PQGH;
  unsigned char DCBA;
  unsigned char NMKJ;
  
};

enum symbol { TIME,DT,DATE,FREESCALE,FIRE,TEMP,SNOWFLAKE,VOLUME,ALARM,T,P,CONTRAST,MODE,AM,
              PM,OM,KWH,AMPS,VOLTS,PROGRAM,VOL,DTx,COLONx,Vx,Tx,A,B};

/////////////////////////////////////////////////////////////////////////////////////////
// Functions
/////////////////////////////////////////////////////////////////////////////////////////
void LCDInit(void);
void LCDBlinkState(void);
void LCDOnOffState(void);
void LCDClear(void);
void LCDPutChar(unsigned char character, unsigned char digit);
void LCDWriteSegment(enum symbol s, unsigned char num);
void LCDClearSegment(enum symbol s, unsigned char num);
void LCDTest(void);