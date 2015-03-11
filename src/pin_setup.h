/*
===============================================================================
 Name: pin_setup.h

 Copyright  (C) 2015 by Kostyantyn Fomin, k.fomin@gmail.com

 Description:
	A common file defining pin setup for PCD8544 LCD Shield mod providing
	LCD backlight control via dedicated PIN.

 Recommended PIN connection:

	LCD pins      Raspberry Pi
	LCD1 - GND    P06  - GND
	LCD2 - VCC    P01 - 3.3V
	LCD3 - CLK    P11 - GPIO0
	LCD4 - Din    P12 - GPIO1
	LCD5 - D/C    P13 - GPIO2
	LCD6 - CS     P15 - GPIO3
	LCD7 - RST    P16 - GPIO4
	LCD8 - LED    P21 - GPIO9

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

// PIN connections in wiringPI number format
// See  http://wiringpi.com/pins/ for reference
#define PIN_SCLK 0
#define PIN_DIN 1
#define PIN_DC 2
#define PIN_CS 3
#define PIN_RST 4
#define PIN_BACKLIGHT 13

// Adjust the contrast of your screen (which might be unique).
// Normal values are 30 - 90. Default is 45.
#define LCD_CONTRAST 75 
