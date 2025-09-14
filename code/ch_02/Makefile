# AVR Project Makefile

# Target microcontroller
MCU = atmega328p

# Target file name (without extension)
TARGET = main

# Compiler and programmer settings
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude
PROGRAMMER = usbasp
PORT = /dev/ttyUSB0

# Compiler flags
CFLAGS = -mmcu=$(MCU) -Os -DF_CPU=16000000UL

# Source files
SRC = main.c uart.c

# Object files
OBJ = $(SRC:.c=.o)

# Default target
all: $(TARGET).hex

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into an ELF file
$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Convert ELF file to HEX file
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Flash the HEX file to the microcontroller
flash: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -U flash:w:$(TARGET).hex:i

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET).elf $(TARGET).hex