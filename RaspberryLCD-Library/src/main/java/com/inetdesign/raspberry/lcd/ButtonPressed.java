package com.inetdesign.raspberry.lcd;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public abstract class ButtonPressed extends Thread {

	static Logger logger = LoggerFactory.getLogger(ButtonPressed.class);

	private static final int BUTTON_PRESSED_UP = 10;
	private static final int BUTTON_PRESSED_DOWN = 11;
	private static final int BUTTON_PRESSED_CENTER = 0;
	private static final int BUTTON_PRESSED_LEFT = 20;
	private static final int BUTTON_PRESSED_RIGHT = 21;

	/**
	 * Create new Thread to recognize button events.
	 */
	public ButtonPressed() {
		this.start();
	}

	@Override
	public void run() {
		while (true) {
			try {
				Thread.sleep(200);
			} catch (InterruptedException e) {
				logger.error("", e);
			}

			int bStatus = RaspiLCD.getInstance().getButtonStatus();

			logger.debug("Button status [" + bStatus + "]");
			if (bStatus == BUTTON_PRESSED_UP || bStatus == BUTTON_PRESSED_DOWN) {
				if (bStatus == BUTTON_PRESSED_UP) {
					logger.debug("BUTTON_PRESSED_UP");
					upButtonPressed();
				} else {
					logger.debug("BUTTON_PRESSED_DOWN");
					downButtonPressed();
				}

			} else if (bStatus == BUTTON_PRESSED_CENTER) {
				logger.debug("BUTTON_PRESSED_CENTER");
				centerButtonPressed();
			} else if (bStatus == BUTTON_PRESSED_LEFT || bStatus == BUTTON_PRESSED_RIGHT) {
				if (bStatus == BUTTON_PRESSED_LEFT) {
					logger.debug("BUTTON_PRESSED_LEFT");
					leftButtonPressed();
				} else {
					logger.debug("BUTTON_PRESSED_RIGHT");
					rightButtonPressed();
				}
			}
		}
	}

	public abstract void upButtonPressed();

	public abstract void downButtonPressed();

	public abstract void centerButtonPressed();

	public abstract void leftButtonPressed();

	public abstract void rightButtonPressed();

}
