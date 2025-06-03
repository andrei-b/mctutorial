# Makefile for AVR project

# Project name
TARGET = main

# Source files
SRC = main.c

# Microcontroller
MCU = atmega328p

# Clock frequency
F_CPU = 16000000UL

# Programmer and port
PROGRAMMER = usbasp
PORT = /dev/ttyACM0
BAUD = 115200

# Tools
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

# Compiler flags
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -std=gnu99 -Wall

# Build rules
all: $(TARGET).hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(SRC:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: $(TARGET).hex
	$(AVRDUDE) -V -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -D -U flash:w:$<

clean:
	rm -f *.o *.elf *.hex
