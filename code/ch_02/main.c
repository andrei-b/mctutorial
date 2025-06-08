#include "uart.h"

void memory_dump(uint8_t *start_address, uint8_t *end_address) {
    // Ensure the start address is less than or equal to the end address
    if (start_address > end_address) {
        uart_send_char('E'); // Send an error message
        uart_send_char('R');
        uart_send_char('R');
        uart_send_char('\n');
        return;
    }

    // Iterate through the memory range and send each byte
    for (uint8_t *ptr = start_address; ptr <= end_address; ptr++) {
        // Send the address
        uart_send_char('0');
        uart_send_char('x');
        uart_send_char("0123456789ABCDEF"[((((uint16_t)ptr) >> 12) & 0xF)]);
        uart_send_char("0123456789ABCDEF"[((((uint16_t)ptr) >> 8) & 0xF)]);
        uart_send_char("0123456789ABCDEF"[((((uint16_t)ptr) >> 4) & 0xF)]);
        uart_send_char("0123456789ABCDEF"[(((uint16_t)ptr) & 0xF)]);
        uart_send_char(':');
        uart_send_char(' ');

        // Send the data at the address
        uart_send_char("0123456789ABCDEF"[((*ptr >> 4) & 0xF)]);
        uart_send_char("0123456789ABCDEF"[(*ptr & 0xF)]);
        uart_send_char('\n');
    }
}

int main(void) {
    // Initialize UART with a baud rate of 9600
    uart_init(9600);

    // Define a memory range for the dump
    uint8_t *start_address = (uint8_t *)0x00; // Example start address
    uint8_t *end_address = (uint8_t *)0x100;  // Example end address

    // Perform the memory dump
    memory_dump(start_address, end_address);

    while (1) {
        // Main loop
    }

    return 0;
}