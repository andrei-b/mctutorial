#!/bin/bash
avrdude -c usbasp -p m328p -U flash:w:optiboot_atmega328.hex
avrdude -c usbasp -p m328p -U lfuse:w:0xFF:m -U hfuse:w:0xDE:m -U efuse:w:0xFD:m
