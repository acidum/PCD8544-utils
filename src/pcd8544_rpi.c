/*
================================================================================
 Name        : pcd8544_rpi.c
 Version     : 0.1

 Copyright (C) 2012 by Andre Wussow, 2012, desk@binerry.de
 PCD8544-utils revision by Kostyantyn Fomin k.fomin@gmail.com

 Description :
     A simple PCD8544 LCD (Nokia3310/5110) for Raspberry Pi for displaying
   some system informations.
	 Makes use of WiringPI-library of Gordon Henderson 
   (https://projects.drogon.net/raspberry-pi/wiringpi/)

	 Recommended connection (http://www.raspberrypi.org/archives/384):
	 LCD pins      Raspberry Pi
	 LCD1 - GND    P06  - GND
	 LCD2 - VCC    P01 - 3.3V
	 LCD3 - CLK    P11 - GPIO0
	 LCD4 - Din    P12 - GPIO1
	 LCD5 - D/C    P13 - GPIO2
	 LCD6 - CS     P15 - GPIO3
	 LCD7 - RST    P16 - GPIO4
	 LCD8 - LED    P01 - 3.3V 

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
#include <signal.h>
#include "PCD8544.h"
#include "pin_setup.h"

void sig_handler(int signo) {
  // clear LCD display before exiting
  LCDclear();
  LCDdisplay();
  exit(0);
}

int main(int argc, char *argv[]) {
 if (signal(SIGINT, sig_handler) == SIG_ERR)
    fprintf(stderr, "\ncan't catch SIGINT\n");
 
 if (signal(SIGTERM, sig_handler) == SIG_ERR)
    fprintf(stderr, "\ncan't catch SIGTERM\n");

  // check wiringPi setup
  if (wiringPiSetup() == -1) {
    fprintf(stderr, "wiringPi-Error\n");
    exit(1);
  }
  
  // init and clear lcd
  LCDInit(PIN_SCLK, PIN_DIN, PIN_DC, PIN_CS, PIN_RST, LCD_CONTRAST);
  LCDclear();
  
  // show logo
  LCDshowLogo();
  
  delay(1500);
  
  for (;;) {
    // clear lcd
    LCDclear();
    
    // get system usage / info
    struct sysinfo sys_info;
    if(sysinfo(&sys_info) != 0) {
      fprintf(stderr, "sysinfo-Error\n");
      exit (1);
    }
    
    // uptime
    char uptimeInfo[15];
    unsigned long uptime = sys_info.uptime / 60;
    sprintf(uptimeInfo, "Up %ld min", uptime);
	  
    // cpu info
    char cpuInfo[15]; 
    unsigned long avgCpuLoad = sys_info.loads[0] / 1000;
    sprintf(cpuInfo, "CPU %ld%%", avgCpuLoad);
  
    // ram info
    char ramInfo[15]; 
    unsigned long totalRam = sys_info.freeram / 1024 / 1024;
    sprintf(ramInfo, "RAM %ld MB", totalRam);

    // IP info
    FILE *fp;
    char ipAddr[45];
    fp = popen("/bin/hostname -I", "r");
    if (fp == NULL) {
      fprintf(stderr, "Failed to run /bin/hostname -I\n" );
      exit(1);
    }
    if (fgets(ipAddr, sizeof(ipAddr)-1, fp) != NULL) {
      LCDdrawstring(0, 34, ipAddr);
    }
    pclose(fp);
    
    // build screen
    LCDdrawstring(0, 0, "System stats");
    LCDdrawline(0, 8, 83, 8, BLACK);
    LCDdrawstring(0, 10, uptimeInfo);
    LCDdrawstring(0, 18, cpuInfo);
    LCDdrawstring(0, 26, ramInfo);
    LCDdrawline(0, 42, 83, 42, BLACK);
    LCDdisplay();
  
    delay(3000);
  }
  
  return 0;
}
