/*
 * Copyright (c) 2013 Stephan Beutel / http://www.i-net-design.com
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
package com.inetdesign.raspberry.lcd.cnative;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Java2LCD {
	static Logger logger = LoggerFactory.getLogger(Java2LCD.class);
	public static boolean libraryLoaded = true;
	static {
		try {
			System.loadLibrary("lcd");
		} catch (SecurityException se) {
			logger.error("SecurityException occured while loading liblcd.so", se);
			libraryLoaded = false;
		} catch (UnsatisfiedLinkError ule) {
			logger.error("UnsatisfiedLinkError occured because liblcd.so doesn't exist", ule);
			libraryLoaded = false;
		} catch (Exception e) {
			logger.error("Exception occured while loading liblcd.so", e);
			libraryLoaded = false;
		}
	}

	public final static native void clearScreen();

	public final static native void setPenColor(long jarg1);

	public final static native void setFillColor(long jarg1);

	public final static native void setFont(long jarg1);

	public final static native void setContrast(long jarg1);

	public final static native void putPixel(long jarg1, long jarg2, long jarg3);

	public final static native void drawLine(long jarg1, long jarg2, long jarg3, long jarg4);

	public final static native void drawCircle(long jarg1, long jarg2, long jarg3);

	public final static native void drawEllipse(int jarg1, int jarg2, int jarg3, int jarg4);

	public final static native void drawRect(long jarg1, long jarg2, long jarg3, long jarg4, long jarg5);

	public final static native void printXY(long jarg1, long jarg2, String jarg3);

	public final static native void drawBitmap(long jarg1, long jarg2, int[] jarg3);

	public final static native void initLcd();

	public final static native void writeFramebuffer();

	public final static native int raspiLcdHwInit();

	public final static native int getButtonStatus();

	public final static native int getRaspberryHwRevision();

	public final static native void setBacklight(long jarg1);

}
