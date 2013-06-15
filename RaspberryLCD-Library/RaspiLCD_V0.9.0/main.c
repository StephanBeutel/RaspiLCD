//--------------------------------------------------------------------------------------------------
//                                  _            _     
//                                 | |          | |    
//      ___ _ __ ___  ___ _   _ ___| |_ ___  ___| |__  
//     / _ \ '_ ` _ \/ __| | | / __| __/ _ \/ __| '_ \. 
//    |  __/ | | | | \__ \ |_| \__ \ ||  __/ (__| | | |
//     \___|_| |_| |_|___/\__,|___/\__\___|\___|_| |_|
//                         __/ |                       
//                        |___/    Engineering (www.emsystech.de)
//
// Filename:    main.c
// Description: Demonstration for RaspiLCD
//    
// Open Source Licensing 
//
// This program is free software: you can redistribute it and/or modify it under the terms of 
// the GNU General Public License as published by the Free Software Foundation,either version 3 
// of the License,or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY; without
// even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with this program.  
// If not,see <http://www.gnu.org/licenses/>.
//
// Dieses Programm ist Freie Software: Sie können es unter den Bedingungen der GNU General Public
// License,wie von der Free Software Foundation,Version 3 der Lizenz oder (nach Ihrer Option) 
// jeder späteren veröffentlichten Version,weiterverbreiten und/oder modifizieren.
//
// Dieses Programm wird in der Hoffnung,dass es nützlich sein wird,aber OHNE JEDE GEWÄHRLEISTUNG,
// bereitgestellt; sogar ohne die implizite Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR 
// EINEN BESTIMMTEN ZWECK. Siehe die GNU General Public License für weitere Details.
//
// Sie sollten eine Kopie der GNU General Public License zusammen mit diesem Programm erhalten 
// haben. Wenn nicht,siehe <http://www.gnu.org/licenses/>.
//                       
// Author:      Martin Steppuhn
// History:     05.09.2012 Initial version
//				18.10.2012 Update vor erster Auslieferung
//				05.11.2012 Version 0.9.0
//--------------------------------------------------------------------------------------------------

//=== Includes =====================================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include "std_c.h"
#include "bcm2835.h"
#include "raspilcd.h"
#include "lcd.h"
#include <jni.h>
#include "Java2LCD.h"

//=== Preprocessing directives (#define) ===========================================================

//=== Type definitions (typedef) ===================================================================

//=== Global constants =============================================================================

//=== Global variables =============================================================================

//=== Local constants  =============================================================================

#include "bmp_raspi.inc"
#include "bmp_men.inc"

//=== Local variables ==============================================================================

uint16  DemoCount;
uint8	DemoView;
char	TempString[32];
uint16	DemoMem[256];

//=== Local function prototypes ====================================================================

//--------------------------------------------------------------------------------------------------
// Name:      Demo Functions
// Function:  
//            
// Parameter: 
// Return:    
//--------------------------------------------------------------------------------------------------

void DemoText(void)
{	
	LCD_ClearScreen();
	LCD_SetFont(1);	
	LCD_PrintXY(30,0,"Raspi-LCD");
	LCD_PrintXY(0,12,"www.emsystech.de");
	LCD_SetFont(0);	
	LCD_PrintXY(8,29,"128 x 64 Pixel (BW)");
	LCD_PrintXY(6,38,"White LED Backlight");
	LCD_PrintXY(4,47,"8 Lines with 21 Char ");
	LCD_PrintXY(4,56,"in the smallest Font ");
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
int main(int argc,char **argv)
{ 
	int Contrast,Backlight;

	Contrast = 9;
	Backlight = 1;
			
	printf("RaspiLCD Demo V0.9 by Martin Steppuhn [" __DATE__ " " __TIME__"]\n");
	printf("RaspberryHwRevision=%i\r\n",GetRaspberryHwRevision());
		
	if(!RaspiLcdHwInit()) { printf("RaspiLcdHwInit() failed!\r\n"); return 1; }
	LCD_Init();			// Init Display
	SetBacklight(1);	// Turn Backlight on
	
	DemoView = 0;
		
	while(1)
	{
		SleepMs(100);
		UpdateButtons();		
			
		if(BUTTON_PRESSED_UP || BUTTON_PRESSED_DOWN)
		{
			if(BUTTON_PRESSED_UP   && (Contrast < 20))  Contrast++; 
			if(BUTTON_PRESSED_DOWN && (Contrast > 0))   Contrast--; 
			LCD_SetContrast(Contrast); 
		}
		if(BUTTON_PRESSED_CENTER)
		{
			Backlight = (Backlight) ? 0 : 1;	// Toggle Backlight
			SetBacklight(Backlight);			// Write to Hardware
		}		
		if(BUTTON_PRESSED_LEFT  && DemoView) DemoView--;		
		if(BUTTON_PRESSED_RIGHT && (DemoView < 6)) DemoView++;		
	
		if(     DemoView == 0)	 DemoText();
					
		LCD_WriteFramebuffer();
	}
	return(0);
}