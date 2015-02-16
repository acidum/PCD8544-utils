# PCD8544-utils
Utilities for PCD8544 LCD (Nokia3310/5110) shield for Raspberry Pi

This utilities are using WiringPi library.
Download and install instructions are on http://wiringpi.com/download-and-install/

# Building

Clone repository and build

```
$ git clone git@github.com:acidum/PCD8544-utils.git
$ cd ./PCD8544-utils
$ make all
```

This will create binaries in ./bin directory.

You may want to edit src/pin_setup.h file to customize PIN numbers and LCD Contrast.


# Usage
Compiled programs require root priveleges to set Raspberry PI GPIO ports.

```
# Continuously print system statistics
$ sudo bin/lcdstats 

# Show Raspberry PI Logo
$ sudo bin/lcdlogo  

# Display text message
$ sudo bin/lcdprint 'Hello world!'

# Turn LED backlight ON, OFF and blinking
$ sudo   bin/lcdlights on
$ sudo   bin/lcdlights off
$ sudo   bin/lcdlights blink
```
