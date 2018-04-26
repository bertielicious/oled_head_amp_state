
/* 
 * File:   config.h
 * Author: Phil
 * Comments:
 * Revision history: 1
 */
#ifndef CONFIG_H
#define	CONFIG_H
// CONFIG

// PIC16F1459 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = CLKDIV6 // CPU System Clock Selection Bit (CPU system clock divided by 6)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
#pragma config PLLEN = ENABLED  // PLL Enable Bit (3x or 4x PLL Enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdbool.h>
#define _XTAL_FREQ 4000000      // 4MHz internal clock frequency
typedef unsigned char uchar;
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

/*******STATE MACHINE STATES*/
#define VOL 0
#define MUTE 1
#define INPUT 2
#define SELECT_IP 3

#define DIAGNOSTIC_LED PORTBbits.RB5    //pin 12 YELLOW LED


/*INPUTS & OUTPUTS*/
#define HI 1
#define LO 0
#define SWIP PORTAbits.RA0          // pin 19

#define VOL_LED PORTBbits.RC1       // pin 15
#define MUTE_LED PORTCbits.RC2      // pin 14
#define INPUT_LED PORTCbits.RC3     // pin 7
#define SELECT_IP_LED PORTCbits.RC4 // pin 6

#define COUNT_MAX 109    // maximum volume reading on OLED display
#define COUNT_MIN 0     // minimum volume reading on OLED display

volatile uchar time_out = 0;  // if time_out = 1, 85 ms has expired
volatile uchar count = 0;
volatile uchar up_down = 0;
volatile uchar previous_count = 0;
volatile uchar tens = 0;
volatile uchar units = 0;

/*OLED STUFF*/

// *****************aliases for PORT pins********************************
#define SCK PORTBbits.RB6       // serial clock pin 11
#define SDO PORTCbits.RC7       // serial data out pin 9
#define RST PORTCbits.RC5       // RESET pin 5
#define DC  PORTCbits.RC6       // D/C data/ command pin 8
#define CS  PORTAbits.RA5       // chip select (active low) pin 2


/*SWIP STUFF*/
#define DT PORTCbits.RC5       // pin 5 interrupt on change pin 5
#define CLK PORTAbits.RA2        // pin 17  interrupt on change


/*OLED display parameters*/
#define SSD1306_128_64
#define SSD1306_LCDWIDTH  128
#define SSD1306_LCDHEIGHT  64

#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETSTARTLINE 0x40
#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_SETSEGMENTREMAP 0xA0
#define SSD1306_SEGREMAP 0xA0

#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETVCOMDETECT 0xDB
#define SSD1306_DISPLAYALLON_RESUME 0xA4    // output follows RAM contents
#define SSD1306_NORMALDISPLAY 0xA6          // white on black or black on white
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_INVERTDISPLAY 0xA6
#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10
#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22
#define SSD1306_COMSCANINC 0xC0
#define SSD1306_SEGREMAP 0xA0
#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A
#define SSD1306_SET_COM_OUTPUT_SCAN_DIRECTION 0xA0

 const uchar V[32] = {0x06,0x0e,0x3c,0xf0,0xc0,0x80,0x00,0x00,
                   0x00,0x80,0xc0,0xf0,0x3c,0x0e,0x06,0x00,
                   0x00,0x00,0x00,0x00,0x01,0x07,0x1e,0x18,
                   0x1e,0x07,0x01,0x00,0x00,0x00,0x00,0x00};
const uchar o[32] = {0x80,0xc0,0xe0,0x60,0x30,0x10,0x10,0x10,
                   0x10,0x10,0x30,0x60,0xe0,0xc0,0x80,0x00,
                   0x03,0x07,0x0f,0x0c,0x18,0x10,0x10,0x10,
                   0x10,0x18,0x0c,0x0f,0x07,0x03,0x00,0x00};
const uchar l[32] = {0x00,0x00,0x02,0x02,0x02,0x02,0xfe,0xfe,
                   0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x1f,
                   0x1f,0x10,0x10,0x10,0x10,0x00,0x00,0x00};
const uchar u[32] = {0x00,0xf0,0xf0,0xf0,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x00,0xf0,0xf0,0xf0,0x00,0x00,
                   0x00,0x0f,0x0f,0x1f,0x18,0x10,0x10,0x10,
                   0x18,0x08,0x0c,0x1f,0x1f,0x1f,0x00,0x00};
const uchar m[32] = {0xf0,0xf0,0xf0,0x20,0x20,0x10,0xf0,0xf0,
                   0xe0,0x20,0x20,0x10,0xf0,0xf0,0xe0,0x00,
                   0x1F,0x1f,0x1f,0x00,0x00,0x00,0x1f,0x1f,
                   0x1f,0x00,0x00,0x00,0x1f,0x1f,0x1f,0x00};
const uchar e[32] = {0x00,0x80,0xc0,0xe0,0x60,0x30,0x10,0x10,
                   0x10,0x10,0x10,0x30,0xe0,0xe0,0xc0,0x00,
                   0x00,0x03,0x07,0x0f,0x0d,0x19,0x11,0x11,
                   0x11,0x11,0x11,0x11,0x11,0x19,0x09,0x00};
/*****************Input********************************************/

const uchar I[32] = {0x00,0x02,0x02,0x02,0x02,0x02,0xfe,0xfe,
                   0xfe,0x02,0x02,0x02,0x02,0x02,0x00,0x00,
                   0x00,0x10,0x10,0x10,0x10,0x10,0x1f,0x1f,
                   0x1f,0x10,0x10,0x10,0x10,0x10,0x00,0x00};
const uchar n[32] = {0x00,0xf0,0xf0,0xf0,0x60,0x20,0x30,0x10,
                   0x10,0x10,0x30,0xf0,0xe0,0xe0,0x00,0x00,
                   0x00,0x1f,0x1f,0x1f,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x00,0x1f,0x1f,0x1f,0x00,0x00};
const uchar p[32] = {0x00,0xf0,0xf0,0xf0,0x60,0x20,0x30,0x10,
                   0x10,0x10,0x30,0xf0,0xe0,0xc0,0x00,0x00,
                   0x00,0xff,0xff,0xff,0x10,0x10,0x10,0x10,
                   0x10,0x18,0x0c,0x0f,0x07,0x03,0x00,0x00};
const uchar t[32] = {0x20,0x20,0x20,0x20,0xfc,0xfc,0xfc,0x20,
                   0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,
                   0x00,0x00,0x00,0x00,0x07,0x0f,0x1f,0x18,
                   0x10,0x10,0x10,0x10,0x10,0x18,0x00,0x00};
const uchar space[32] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                       0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                       0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                       0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
/*****************rest of alphabet***************************************/

const uchar a[32] = {0x00,0x80,0xc0,0xe0,0x60,0x30,0x10,0x10,
                   0x10,0x10,0x10,0xf0,0xf0,0xf0,0x00,0x00,
                   0x00,0x07,0x0f,0x1f,0x30,0x20,0x20,0x20,
                   0x18,0x08,0x0c,0x1f,0x1f,0x1f,0x00,0x00};

const uchar i[32] = {0x00,0x00,0x10,0x10,0x10,0x10,0xf2,0xf2,
                   0xf2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x1f,
                   0x1f, 0x10,0x10,0x10,0x10,0x00,0x00,0x00};
const uchar f[32] = {0x40,0x40,0x40,0xf8,0xfc,0xfc,0x06,0x06,
                   0x42,0x42,0x42,0x42,0x42,0x02,0x02,0x00,
                   0x00,0x00,0x00,0x1f,0x1f,0x1f,0x00,0x00,
                   0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00};
const uchar h[32] = {0x00,0xfe,0xfe,0xfe,0x60,0x20,0x30,0x10,
                   0x10,0x10,0x30,0xf0,0xe0,0xe0,0x00,0x00,
                   0x00,0x1f,0x1f,0x1f,0x00,0x00,0x00,0x00,
                   0x00, 0x00,0x00,0x1f,0x1f,0x1f,0x00,0x00};
const uchar g[32] = {0x00,0x80,0xc0,0xe0,0x60,0x30,0x10,0x10,
                   0x10,0x10,0x10,0xf0,0xf0,0xf0,0x00,0x00,
                   0x00,0x47,0xcf,0x9f,0x98,0x90,0x90,0x90,
                   0x98, 0x88,0xcc,0x7f,0x7f,0x3f,0x00,0x00};
const uchar r[32] = {0x00,0x00,0xf0,0xf0,0xf0,0x60,0x20,0x30,
                   0x10,0x10,0x70,0x70,0x70,0x00,0x00,0x00,
                   0x00,0x00,0x1f,0x1f,0x18,0x00,0x00,0x00,
                   0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00};
const uchar M[32] = {0xfe,0xfe,0x1e,0x38,0xf0,0xc0,0x00,0x00,
                   0x00,0xc0,0xf0,0x38,0x0e,0xfe,0xfe,0x00,
                   0x01f,0x1f,0x00,0x00,0x00,0x01,0x07,0x06,
                   0x07,0x01,0x00,0x00,0x00,0x1f,0x1f,0x00};
const uchar N[32] = {0x00,0xfe,0xfe,0xfe,0x1c,0x38,0x70,0xc0,
                   0x80,0x00,0x00,0xfe,0xfe,0xfe,0x00,0x00,
                   0x00,0x1f,0x1f,0x1f,0x00,0x00,0x00,0x00,
                   0x03,0x07,0x0e,0x1f,0x1f,0x1f,0x00,0x00};
const uchar b[32] = {0x00,0x00,0xfe,0xfe,0xfe,0x40,0x20,0x30,
                   0x10,0x10,0x10,0x20,0xf0,0xe0,0xc0,0x00,
                   0x00,0x00,0x1f,0x1f,0x1f,0x10,0x10,0x10,
                   0x10,0x10,0x18,0x0c,0x0f,0x07,0x03,0x00};
const uchar x[32] = {0x00,0x10,0x30,0x30,0x60,0xc0,0x80,0x80,
                   0x80,0xc0,0x60,0x30,0x10,0x10,0x00,0x00,
                   0x10,0x10,0x18,0x0c,0x06,0x06,0x03,0x01,
                   0x03,0x06,0x06,0x0c,0x18,0x10,0x10,0x00};
const uchar d[32] = {0x00,0x00,0x80,0xc0,0xe0,0x60,0x30,0x10,
                   0x10,0x10,0x10,0x10,0xfe,0xfe,0xfe,0x00,
                   0x00,0x00,0x07,0x0f,0x1f,0x18,0x10,0x10,
                   0x10,0x18,0x08,0x0c,0x1f,0x1f,0x1f,0x00};
const uchar B[32] = {0x00,0xfe,0xfe,0xfe,0x42,0x42,0x42,0x42,
                   0x42,0x62,0xe6,0x20,0x1c,0x1c,0x00,0x00,
                   0x00,0x3f,0x3f,0x3f,0x20,0x20,0x20,0x20,
                   0x20,0x20,0x30,0x31,0x0f,0x0f,0x07,0x00};
const uchar minus[32] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                   0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,
                   0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00};
/* *************************numbers from 0 to 9**************************/

const uchar cero[32] = {0xf0,0xf8,0xfc,0x0c,0x06,0x02,0x02,0x02,
                      0x62,0x32,0x1c,0x1c,0xf8,0xf0,0xe0,0x00,
                      0x01,0x03,0x07,0x0e,0x0e,0x13,0x11,0x10,
                      0x10,0x10,0x18,0x0e,0x0f,0x07,0x03,0x00};
const uchar uno[32] =  {0x00,0x08,0x04,0x04,0x04,0x02,0xfe,0xfe,
                      0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                      0x00,0x10,0x10,0x10,0x10,0x10,0x1f,0x1f,
                      0x1f,0x10,0x10,0x10,0x10,0x10,0x00,0x00};
const uchar dos[32] =  {0x00,0x04,0x06,0x02,0x02,0x02,0x82,0x82,
                      0xc2,0x62,0x66,0x3e,0x1c,0x1c,0x00,0x00,
                      0x18,0x1c,0x1e,0x12,0x12,0x13,0x11,0x10,
                      0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00};
const uchar tres[32] = {0x00,0x04,0x04,0x42,0x42,0x42,0x42,0x42,
                      0x62, 0xe6,0xbe,0xbc,0x98,0x00,0x00,0x00,
                      0x00,0x08,0x18,0x10,0x10,0x10,0x10,0x10,
                      0x10,0x18,0x08,0x0f,0x0f,0x07,0x00,0x00};
const uchar cuatro[32] = {0x00,0x80,0xc0,0xe0,0x70,0x78,0x3c,0x1e,
                      0xfe,0xfe,0xfe,0x00,0x00,0x00,0x00,0x00,
                      0x03,0x03,0x03,0x02,0x02,0x02,0x02,0x02,
                      0x1f,0x1f,0x1f,0x02,0x02,0x02,0x02,0x02};
const uchar cinco[32] = {0x00,0x3e,0x3e,0x3e,0x22,0x22,0x22,0x22,
                      0x62,0x62,0xc2,0xc2,0x82,0x80,0x00,0x00,
                      0x00,0x08,0x10,0x10,0x10,0x10,0x10,0x10,
                      0x10,0x18,0x0c,0x0f, 0x07,0x03,0x00,0x00};
const uchar seis[32] =  {0x00,0xe0,0xf8,0xfc,0x8c,0x44,0x46,0x22,
                       0x22,0x22,0x22,0x62,0xc2,0xc0,0x80,0x00,
                       0x00,0x03,0x07,0x0f,0x0f,0x18,0x10,0x10,
                       0x10,0x10,0x18,0x1c,0x0f,0x07,0x03,0x00};
const uchar siete[32] = {0x00,0x02,0x02,0x02,0x02,0x02,0x82,0xc2,
                       0xe2,0x72,0x32,0x1a,0x0e,0x0e,0x06,0x00,
                       0x00,0x00,0x00,0x1c,0x1e,0x1f,0x03,0x00,
                       0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
const uchar ocho[32] =  {0x00,0x00,0x18,0xbc,0xbe,0xe2,0x62,0x42,
                       0x42,0xe2,0xbe,0xbc,0x1c,0x00,0x00,0x00,
                       0x00,0x06,0x0f,0x1f,0x19,0x10,0x10,0x10,
                       0x10,0x10,0x19,0x0f,0x0f,0x06,0x00,0x00};
const uchar nueve[32] = {0x70,0xf8,0xfc,0x8c,0x06,0x02,0x02,0x02,
                       0x02,0x82,0x86,0x7c,0xfc,0xf8,0xf0,0x00,
                       0x00,0x00,0x10,0x11,0x11,0x11,0x11,0x11,
                       0x11,0x18,0x08,0x0c,0x07,0x07,0x01,0x00};
#endif	/* CONFIG_H */