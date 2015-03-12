/*
===============================================================================
 Name : lcdlight.c

 Descriptioni : 
     Controls the backlight LED.

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

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>
#include "pin_setup.h"

void sig_handler(int signo) {
  // turning lights off before exit
  digitalWrite(PIN_BACKLIGHT, 0);
  exit(0);
}

int main (int argc, char *argv[]) {
  void usage () {
    fprintf(stderr, "usage: %s [on|off|blink]\n", argv[0]);
    exit(1);
  }

  if (wiringPiSetup () == -1) {
    exit(1);
  }

  pinMode (PIN_BACKLIGHT, OUTPUT); 

  if (argc == 1) {
    usage();
  }

  if (strcmp(argv[1], "blink") == 0) {
    if (signal(SIGINT, sig_handler) == SIG_ERR) 
      fprintf(stderr,"\ncan't catch SIGINT\n");
    if (signal(SIGTERM, sig_handler) == SIG_ERR) 
      fprintf(stderr,"\ncan't catch SIGTERM\n");

    while(1) {
      digitalWrite (PIN_BACKLIGHT, 1);
      delay (250);
      digitalWrite (PIN_BACKLIGHT, 0);
      delay (250);
    }
  } else if (strcmp(argv[1], "on") == 0) {
    digitalWrite (PIN_BACKLIGHT, 1);
  } else if (strcmp(argv[1], "off") == 0) {
    digitalWrite (PIN_BACKLIGHT, 0);
  } else {
    usage();
  }
}
