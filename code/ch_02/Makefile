MCU = atmega328p
F_CPU = 16000000UL
BAUD = 9600
PROGRAMMER = usbasp
PORT = /dev/ttyUSB0

CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall
LDFLAGS = -Wl,--section-start=.text=0x7C00

TARGET = bootloader
SRC = bootloader.c

all: $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -U flash:w:$(TARGET).hex

fuse:
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) \
		-U lfuse:w:0xFF:m \
		-U hfuse:w:0xD6:m \
		-U efuse:w:0xFD:m

clean:
	rm -f *.elf *.hex
