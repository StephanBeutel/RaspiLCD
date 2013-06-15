
CC = gcc

#CFLAGS  = -mtune=arm1176jzf-s -mfpu=vfp -mfloat-abi=hard -marmv6z -Wall
CFLAGS  = -mtune=arm1176jzf-s -mfpu=vfp -mfloat-abi=hard -marm -O3 -Wall -I/opt/jdk1.8.0/include -I/opt/jdk1.8.0/include/linux
LD = ld
LDFLAGS = -lrt


OBJ = main.o bcm2835.o lcd.o raspilcd.o Java2LCD.o
BIN = raspilcd

lcd.so: gpio
	$(CC) -shared bcm2835.o lcd.o raspilcd.o Java2LCD.o -o liblcd.so $(CFLAGS) $(LDFLAGS)

gpio: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -rf $(BIN) $(OBJ)
