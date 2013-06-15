package com.inetdesign.raspberry.lcd.util;

import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import javax.imageio.ImageIO;

import org.apache.commons.codec.binary.Base64;

public class DisplayUtils {

	private int i = 0;
	private int space = 0;
	private int textLenght = 0;
	private int frontSpacer = 0;

	private String text = null;
	private Integer maxChars = -1;

	/**
	 * Create a utility for running text. Static method to calculate line height
	 * for all lines with a given font size.
	 * 
	 * @param text
	 * @param fontSize
	 */
	public DisplayUtils(String text, int fontSize) {
		this.text = text;
		setMaxChars(fontSize);
	}

	private void setMaxChars(int fontSize) {
		switch (fontSize) {
		case 0:
			this.maxChars = 21;
			break;
		case 1:
			this.maxChars = 16;
			break;
		case 2:
			this.maxChars = 13;
			break;
		case 3:
			this.maxChars = 11;
			break;
		default:
			this.maxChars = 11;
			break;
		}
	}

	/**
	 * Create a running text if the given string is to long for the display.
	 * 
	 * @return
	 */
	public String cutLongString() {
		if (text.length() <= maxChars) {
			return text;
		}
		if (space == maxChars - 1) {
			space = 0;
			i = 0;
			frontSpacer = maxChars - 1;
		}
		if (i + maxChars > text.length()) {
			space = (i + maxChars) - text.length();
			textLenght = text.length();
		} else {
			textLenght = maxChars + i;
		}
		String t = "";
		for (int j = 0; j < frontSpacer; j++) {
			t += " ";
		}

		t += text.substring(0 + i, textLenght - frontSpacer);
		for (int j = 0; j < space; j++) {
			t += " ";
		}

		if (frontSpacer > 0) {
			frontSpacer--;
		} else {
			i++;
		}
		return t;
	}

	/**
	 * Get the y line heights for all possible lines for a given font size.
	 * 
	 * @return
	 */
	public static Map<Integer, Integer> getLineCoords(Integer fontSize) {
		Map<Integer, Integer> returnValue = new HashMap<>();
		int line = 0;
		int height = 0;
		switch (fontSize) {
		case 0:
			height = 9;
			break;
		case 1:
			height = 16;
			break;
		case 2:
			height = 16;
			break;
		case 3:
			height = 20;
			break;
		default:
			height = 8;
			break;
		}
		for (int i = 0; i < 64; i += height) {
			if (i + height <= 64) {
				returnValue.put(line, i);
			}
			line++;
		}

		return returnValue;
	}

	public void setNewFontSize(Integer fontSize) {
		setMaxChars(fontSize);
		reset();
	}

	public void reset() {
		i = 0;
		space = 0;
		textLenght = 0;
		frontSpacer = 0;
	}

	public static int[] convertImage(File image) throws IOException {

		BufferedImage img = ImageIO.read(image);
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		ImageIO.write(img, "png", baos);

		byte[] res = baos.toByteArray();
		byte[] encodedImage = Base64.encodeBase64(baos.toByteArray());

		int[] intData = new int[encodedImage.length + 2];
		intData[0] = img.getWidth();
		intData[1] = img.getHeight();
		for (int i = 2; i < encodedImage.length + 2; i++) {

			intData[i] = Integer.valueOf(String.valueOf(encodedImage[i - 2]));
		}

		return intData;
	}

}
