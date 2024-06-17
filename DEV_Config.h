/*****************************************************************************
* | File        :   DEV_Config.c
* | Author      :   Waveshare team
* | Function    :   Hardware underlying interface
* | Info        :
*                Used to shield the underlying layers of each master 
*                and enhance portability
*----------------
* | This version:   V1.0
* | Date        :   2018-11-22
* | Info        :
* 
* 5/21/2024 Glaive: Add parameter DEV_SPI_FREQUENCY to specify maximum frequency of this device.

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
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
#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_

#include <stdint.h>
#include <stdio.h>
#include <SPI.h>

// Minimum frequency for this device is as slow as you want
// Maximum frequency is given by this parameter (10 MHz)

#define DEV_SPI_FREQUENCY 10000000

/**
 * GPIO config
**/

// The following pins are optional, but these are the default values:
#define DEV_CS_PIN  D10   // yellow wire
#define DEV_DC_PIN  D7    // blue wire
#define DEV_RST_PIN D8    // brown wire
#define DEV_BL_PIN  D9    // gray wire (back light)

/**
 * GPIO read and write
**/
#define DEV_Digital_Write(_pin, _value) digitalWrite(_pin, _value == 0? LOW:HIGH)
#define DEV_Digital_Read(_pin) digitalRead(_pin)


/**
 * SPI
**/
#define DEV_SPI_WRITE(_dat)   SPI.transfer(_dat)

/**
 * delay x ms
**/
#define DEV_Delay_ms(__xms)    delay(__xms)


/*-----------------------------------------------------------------------------*/
 void Config_Init();
#endif
