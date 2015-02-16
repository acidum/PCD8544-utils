/*
=================================================================================
 Name        : lcdlogo.c

 Description :
     Simply clear the LCD and display Rapberry PI logo.

================================================================================
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.
================================================================================
 */

#include <wiringPi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include "PCD8544.h"
#include "pin_setup.h"

  
int main (void) {
  if (wiringPiSetup() == -1) {
    fprintf(stderr, "wiringPi-Error\n");
    exit(1);
  }
  
  LCDInit(PIN_SCLK, PIN_DIN, PIN_DC, PIN_CS, PIN_RST, LCD_CONTRAST);
  LCDclear();
  LCDshowLogo();
 
 return 0;
}
