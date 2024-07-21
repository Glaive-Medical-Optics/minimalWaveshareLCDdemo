/*****************************************************************************
* | File        :   minimalWWWforWaveshareLCD (Minimal Window Within Window)
* | Author      :   Glaive softwear team
* | This version:   V1.1
* | Date        :   18-July-2024
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/

/*
 * 
 *    This sketch displays a fish or a stylized "G" that moves around
 *    on the Waveshare LCD module using the SPI interface on an Arduino Giga R1 board.
 *    
 *    The pin connections must be set up as follows:
 *    
 *    LCD pin     wire color    Arduino pin
 *    -------     ----------    -----------
 *    VCC         purple        5V            required
 *    GND         white         GND           required
 *    DIN         green         D90 (COPI)    required  (on SPI 6-pin connector)
 *    CLK         orange        D91 (SCK)     required  (on SPI 6-pin connector)
 *    CS          yellow        D10           optional
 *    DC          blue          D7            optional
 *    RST         brown         D8            optional
 *    BL          gray          D9            optional
 *    
 *    This demo is set up to use pins D7, D8, D9, and D10 as shown in the table above.
 *    You can replace these pins by any digital pins.
 *    To do that, specify the pins you are using in the file DEV_Config.h.
 *    
 *    This program is Free Software and has ABSOLUTELY NO WARRANTY.
 */

#include "LCD_Driver.h"

#define WWW_width     70
#define WWW_height    70
#define WWW_startRow  100
#define WWW_startCol  50

void setup()
{
  Serial.begin(9600);   // for print debugging
  delay(4000);          //delay 4 seconds to give the serial port enough time to initialize
  Serial.print("\nStarting...\n");
  Config_Init();
  Serial.print("Config succeeded.\n");
  LCD_Init();
  Serial.print("LCD_Init succeeded.\n");
  delay(2000);
  //quickMoveG();       // Uncomment this line to move a stylized G on the screen
  createWWW(WWW_startCol,WWW_startRow,WWW_width,WWW_height);
  
  Serial.print("exiting setup.\n");

}

void loop()
{

}
