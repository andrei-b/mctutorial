import serial
import time

PAGE_SIZE = 128
BOOTLOADER_PORT = '/dev/ttyACM0'
BAUD = 9600

def load_binary(filename):
    with open(filename, 'rb') as f:
        data = f.read()
    if len(data) % PAGE_SIZE != 0:
        data += b'\xFF' * (PAGE_SIZE - len(data) % PAGE_SIZE)
    return data

def flash_binary(data):
    ser = serial.Serial(BOOTLOADER_PORT, BAUD, timeout=1)
    time.sleep(0.5)

    for addr in range(0, len(data), PAGE_SIZE):
        page = data[addr:addr+PAGE_SIZE]
        addr_word = addr // 2  # Flash address is in words
        ser.write(bytes([0x01, addr_word & 0xFF, (addr_word >> 8) & 0xFF]))
        ser.write(page)
        ack = ser.read(1)
        if ack != b'K':
            print(f"Error at address {addr:#04x}")
            break
        print(f"Flashed page at {addr:#04x}")
    
    ser.write(b'\x00')  # Done command
    ser.close()

if __name__ == "__main__":
    bin_data = load_binary("program.bin")
    flash_binary(bin_data)
