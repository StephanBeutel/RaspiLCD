/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_inetdesign_raspberry_lcd_cnative_Java2LCD */

#ifndef _Included_com_inetdesign_raspberry_lcd_cnative_Java2LCD
#define _Included_com_inetdesign_raspberry_lcd_cnative_Java2LCD
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    clearScreen
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_clearScreen
  (JNIEnv *, jclass);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    setPenColor
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_setPenColor
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    setFillColor
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_setFillColor
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    setFont
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_setFont
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    setContrast
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_setContrast
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    putPixel
 * Signature: (JJJ)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_putPixel
  (JNIEnv *, jclass, jlong, jlong, jlong);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    drawLine
 * Signature: (JJJJ)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_drawLine
  (JNIEnv *, jclass, jlong, jlong, jlong, jlong);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    drawCircle
 * Signature: (JJJ)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_drawCircle
  (JNIEnv *, jclass, jlong, jlong, jlong);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    drawEllipse
 * Signature: (IIII)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_drawEllipse
  (JNIEnv *, jclass, jint, jint, jint, jint);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    drawRect
 * Signature: (JJJJJ)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_drawRect
  (JNIEnv *, jclass, jlong, jlong, jlong, jlong, jlong);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    printXY
 * Signature: (JJLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_printXY
  (JNIEnv *, jclass, jlong, jlong, jstring);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    drawBitmap
 * Signature: (JJ[I)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_drawBitmap
  (JNIEnv *, jclass, jlong, jlong, jintArray);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    initLcd
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_initLcd
  (JNIEnv *, jclass);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    writeFramebuffer
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_writeFramebuffer
  (JNIEnv *, jclass);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    raspiLcdHwInit
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_raspiLcdHwInit
  (JNIEnv *, jclass);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    getButtonStatus
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_getButtonStatus
  (JNIEnv *, jclass);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    getRaspberryHwRevision
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_getRaspberryHwRevision
  (JNIEnv *, jclass);

/*
 * Class:     com_inetdesign_raspberry_lcd_cnative_Java2LCD
 * Method:    setBacklight
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_inetdesign_raspberry_lcd_cnative_Java2LCD_setBacklight
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif