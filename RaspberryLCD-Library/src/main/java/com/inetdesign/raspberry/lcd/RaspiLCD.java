package com.inetdesign.raspberry.lcd;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.inetdesign.raspberry.lcd.cnative.Java2LCD;

public final class RaspiLCD {
	static Logger logger = LoggerFactory.getLogger(RaspiLCD.class);

	private static boolean backlight = true;
	private static int contrast = 9;
	private static RaspiLCD instance = null;

	/**
	 * Initialize the display.
	 */
	static {
		if (Java2LCD.libraryLoaded) {
			Java2LCD.raspiLcdHwInit();
			Java2LCD.initLcd();
		} else {
			logger.debug("init LCD display");
		}
	}

	/**
	 * Only one display, only one instance available.
	 * 
	 * @return
	 */
	public static RaspiLCD getInstance() {
		if (instance == null) {
			instance = new RaspiLCD();
		}
		instance.setBacklight(backlight);
		return instance;
	}

	/**
	 * Only one display, only one instance available.
	 * 
	 * @param backlight
	 * @return
	 */
	public static RaspiLCD getInstance(boolean backlight) {
		if (instance == null) {
			instance = new RaspiLCD();
		}
		instance.setBacklight(backlight);
		return instance;
	}

	/**
	 * Private contructor. Use getInstance().
	 */
	private RaspiLCD() {
		setContrast(9);
	}

	/**
	 * Get backlight status.
	 * 
	 * @return
	 */
	public boolean isBacklight() {
		return backlight;
	}

	/**
	 * Turn backlight on or off.
	 * 
	 * @param backlight
	 */
	public void setBacklight(boolean backlight) {
		RaspiLCD.backlight = backlight;
		logger.debug("setBacklight [" + (RaspiLCD.backlight ? "ON" : "OFF") + "]");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.setBacklight(backlight ? 1 : 0);
		}
	}

	/**
	 * Switch backlight to opposite status.
	 */
	public void toggleBacklicht() {
		RaspiLCD.backlight = !RaspiLCD.backlight;
		logger.debug("toggleBacklicht [" + (RaspiLCD.backlight ? "ON" : "OFF") + "]");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.setBacklight(RaspiLCD.backlight ? 1 : 0);
		}
	}

	/**
	 * Get the actual display contrast.
	 * 
	 * @return
	 */
	public int getContrast() {
		return contrast;
	}

	/**
	 * Set display cntrast.
	 * 
	 * @param contrast
	 *            (0..63)
	 */
	public void setContrast(int contrast) {
		int c = contrast > 63 ? 63 : contrast;
		c = c < 0 ? 0 : c;
		logger.debug("setContrast [" + RaspiLCD.contrast + "]");
		RaspiLCD.contrast = c;
		if (Java2LCD.libraryLoaded) {
			Java2LCD.setContrast(c);
		}
	}

	/**
	 * Increase contrast by 1.
	 */
	public void increaseContrast() {
		if (contrast < 63) {
			RaspiLCD.contrast++;
			logger.debug("increaseContrast to [" + RaspiLCD.contrast + "]");
			if (Java2LCD.libraryLoaded) {
				Java2LCD.setContrast(contrast);
			}
		} else {
			logger.debug("Contrast already maximum [" + RaspiLCD.contrast + "], cannot be increased");
		}
	}

	/**
	 * Decrease contrast by 1.
	 */
	public void decreaseContrast() {
		if (contrast > 0) {
			RaspiLCD.contrast--;
			logger.debug("decreaseContrast to " + RaspiLCD.contrast);
			if (Java2LCD.libraryLoaded) {
				Java2LCD.setContrast(contrast);
			}
		} else {
			logger.debug("Contrast already minimum [" + RaspiLCD.contrast + "], cannot be decreased");
		}
	}

	/**
	 * Set font.
	 * 
	 * @param size
	 *            0..3 for Fonts
	 */
	public void setFont(int size) {
		logger.debug("setFont to [" + size + "]");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.setFont(size);
		}
	}

	/**
	 * Print text to screen using xy values and a string.
	 * 
	 * @param x
	 * @param y
	 * @param text
	 */
	public void printXY(int x, int y, String text) {
		logger.debug("printXY X[" + x + "] Y[" + y + "] \"" + text + "\"");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.printXY(x, y, text);
		}
	}

	/**
	 * Transfer Framebuffer (RAM) to display via SPI.
	 */
	public void writeFramebuffer() {
		logger.debug("writeFramebuffer");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.writeFramebuffer();
		}
	}

	/**
	 * Delete screen content.
	 */
	public void clearScreen() {
		logger.debug("clearScreen");
		logger.debug("---------------------------------------------------------------------------------");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.writeFramebuffer();
			Java2LCD.clearScreen();
			Java2LCD.writeFramebuffer();
		}
	}

	/**
	 * Update button status and get pressed button.
	 * 
	 * @return
	 */
	protected int getButtonStatus() {
		logger.debug("getButtonStatus");
		if (Java2LCD.libraryLoaded) {
			return Java2LCD.getButtonStatus();
		} else {
			return -1;
		}
	}

	/**
	 * Set pen color.
	 * 
	 * @param color
	 *            0=White 1=Black
	 */
	public void setPenColor(int color) {
		logger.debug("setPenColor");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.setPenColor(color);
		}
	}

	/**
	 * Set fill color.
	 * 
	 * @param color
	 *            -1=transparent, 0=white, 1=black
	 */
	public void setFillColor(int color) {
		logger.debug("setFillColor");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.setFillColor(color);
		}
	}

	/**
	 * Set single pixel at x,y.
	 * 
	 * @param x
	 * @param y
	 * @param color
	 */
	public void putPixel(int x, int y, int color) {
		logger.debug("putPixel");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.putPixel(x, y, color);
		}
	}

	/**
	 * Draw line from xy to xy.
	 * 
	 * @param x0
	 * @param y0
	 * @param x1
	 * @param y1
	 */
	public void drawLine(int x0, int y0, int x1, int y1) {
		logger.debug("drawLine");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.drawLine(x0, y0, x1, y1);
		}
	}

	/**
	 * Draw circle with centerpont an radius linewidth=1 pixel, no fill.
	 * 
	 * @param x
	 * @param y
	 * @param radius
	 */
	public void drawCircle(int x, int y, int radius) {
		logger.debug("drawCircle");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.drawCircle(x, y, radius);
		}
	}

	/**
	 * Draw ellipse with centerpont an "radius" linewidth=1 pixel, no fill.
	 * 
	 * @param xm
	 * @param ym
	 * @param a
	 * @param b
	 */
	public void drawEllipse(int xm, int ym, int a, int b) {
		logger.debug("drawEllipse");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.drawLine(xm, ym, a, b);
		}
	}

	/**
	 * Draw rectangle, with pencolor and fillcolor. Two diagonal points and
	 * linewidth.
	 * 
	 * @param x0
	 * @param y0
	 * @param x1
	 * @param y1
	 * @param line
	 */
	public void drawRect(int x0, int y0, int x1, int y1, int line) {
		logger.debug("drawRect");
		if (Java2LCD.libraryLoaded) {
			Java2LCD.drawRect(x0, y0, x1, y1, line);
		}
	}

	/**
	 * Startpoint xy, bitMapArray of image.
	 * 
	 * @param x
	 * @param y
	 * @param bitmaparray
	 */
	public void drawBitmap(int x, int y, int[] bitMapArray) {
		logger.debug("drawBitmap");
		if (Java2LCD.libraryLoaded) {
			if (bitMapArray != null) {
				Java2LCD.drawBitmap(x, y, bitMapArray);
			} else {
				logger.error("bitMapArray is null");
			}
		}
	}

	/**
	 * Get Raspberry Pi hardware version.
	 * 
	 * @return
	 */
	public int getRaspberryHwRevision() {
		logger.debug("getRaspberryHwRevision");
		if (Java2LCD.libraryLoaded) {
			return Java2LCD.getRaspberryHwRevision();
		} else {
			return -1;
		}
	}

}
