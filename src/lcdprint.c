/*
=================================================================================
 Name        : lcdprint.c

 Description :
     Clear the LCD and display and print a specified text message.

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
 
int main (int argc, char *argv[])
{
  if (2  > argc)
  {
    fprintf(stderr, "usage: %s message\n", argv[0]);
    exit(1);
  }
  
  if (wiringPiSetup() == -1) {
    fprintf(stderr, "wiringPi-Error\n");
    exit(1);
  }
  
  LCDInit(PIN_SCLK, PIN_DIN, PIN_DC, PIN_CS, PIN_RST, LCD_CONTRAST);
  LCDclear();
  LCDdrawstring(0, 0, argv[1]);
  LCDdisplay();  
 
 return 0;
}
