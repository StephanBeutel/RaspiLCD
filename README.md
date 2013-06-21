RaspiLCD
========

This library is released under Apache License 2.0.

Library to access the LCD display from EmSysTech from a Java programm.

Based on the original C-Code from Emsystech: http://www.emsystech.de/produkt/raspi-lcd/

Requirements:
=============
- Raspberry Pi hardware with LCD display from Emsystech and Debian Linux.
- Java JDK 1.7.x+
- Maven 3
- GCC compiler
- Make tools

Instructions:
=============
1. Checkout this repository to your Raspberry Pi.
2. Change directory to RaspiLCD/RaspberryLCD-Library/RaspiLCD_V0.9.0
3. Build the library using the 'make' command.
4. Change directory to RaspiLCD/RaspberryLCD-Library
5. Use Maven to build the Java library 'mvn clean install'

6. To start the demo project please take a look at the run.sh script in the demo project folder and change the path to the folder the library is included.
6. Take a look into the Demo project how to use the library in your project.



Development:
============
The library uses log4j to display access of the library access in the Java console
and does not require the display access and Raspberry Po hardware in development mode
So you can develop your software on a good and powerful computer and only build it
on the Raspberry Pi when you want to test it on the real hardware.