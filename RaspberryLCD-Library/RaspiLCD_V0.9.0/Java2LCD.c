
#include <stdio.h>
#include "lcd.h"
#include "raspilcd.h"
#include <jni.h>
#include "Java2LCD.h"

// JNI methods
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_clearScreen
  (JNIEnv *env,jclass clazz)
  {
	LCD_ClearScreen();
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_setPenColor
  (JNIEnv *env,jclass clazz,jlong color)
  {
	LCD_SetPenColor(color);
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_setFillColor
  (JNIEnv *env,jclass clazz,jlong color)
  {
	LCD_SetFillColor(color);
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_setFont
  (JNIEnv *env,jclass clazz,jlong font)
  {
	LCD_SetFont(font);
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_setContrast
  (JNIEnv *env,jclass clazz,jlong c)
  {
	LCD_SetContrast(c); 
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_putPixel
  (JNIEnv *env,jclass clazz,jlong x0,jlong y0,jlong color)
  {
	LCD_PutPixel(x0,y0,color);
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_drawLine
  (JNIEnv *env,jclass clazz,jlong x0,jlong y0,jlong x1,jlong y1)
  {
	LCD_DrawLine(x0,y0,x1,y1);
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_drawCircle
  (JNIEnv *env,jclass clazz,jlong x0,jlong y0,jlong radius)
  {
	LCD_DrawCircle(x0,y0,radius);
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_drawEllipse
  (JNIEnv *env,jclass clazz,jint xm,jint ym,jint a,jint b)
  {
	LCD_DrawEllipse(xm,ym,a,b);
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_drawRect
  (JNIEnv *env,jclass clazz,jlong x0,jlong y0,jlong x1,jlong y1,jlong line)
  {
	LCD_DrawRect(x0,y0,x1,y1,line);
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_printXY
  (JNIEnv *env,jclass clazz,jlong x0,jlong y0,jstring text)
  {
	const char *nativeString = (*env)->GetStringUTFChars(env, text, 0);
	LCD_PrintXY(x0,y0,nativeString);	
	(*env)->ReleaseStringUTFChars(env, text, nativeString);
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_drawBitmap
  (JNIEnv *env,jclass clazz,jlong x0,jlong y0,jintArray bmp)
  {  
	uint8 *nbmp = (*env)->GetIntArrayElements(env, bmp, 0);
    LCD_DrawBitmap(x0,y0,nbmp);
	(*env)->ReleaseIntArrayElements(env, bmp, nbmp, 0);
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_initLcd
  (JNIEnv *env,jclass clazz)
  {
	LCD_Init();
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_writeFramebuffer
  (JNIEnv *env,jclass clazz)
  {
	LCD_WriteFramebuffer();
  }

JNIEXPORT jint JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_raspiLcdHwInit
  (JNIEnv *env,jclass clazz)
  {
	return RaspiLcdHwInit();
  }

JNIEXPORT jint JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_getButtonStatus
  (JNIEnv *env,jclass clazz)
  {
	UpdateButtons();
	if(BUTTON_PRESSED_UP) return 10; 
	else if(BUTTON_PRESSED_DOWN) return 11; 
	else if(BUTTON_PRESSED_CENTER) return 0;		
	else if(BUTTON_PRESSED_LEFT) return 20;		
	else if(BUTTON_PRESSED_RIGHT) return 21;	
	return -1;
  }

JNIEXPORT jint JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_getRaspberryHwRevision
  (JNIEnv *env,jclass clazz)
  {
	return GetRaspberryHwRevision();
  }

JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_setBacklight
  (JNIEnv *env,jclass clazz,jlong onOff)
  {
	SetBacklight(onOff);
  }

