#include "uart.h"
#include <avr/interrupt.h>

void uart_init(uint32_t baud) {
    // Set the baud rate
    uint16_t ubrr = (F_CPU / (16UL * baud)) - 1;
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)(ubrr & 0xFF);

    // Enable receiver and transmitter
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    // Set the frame format: 8 data bits, no parity, 1 stop bit
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}


void uart_send_char(char data) {
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0))) {
       // __asm__ __volatile__("nop"); // No-operation to prevent busy-waiting
    }
    // Put data into buffer, sends the data
    UDR0 = data;
}

char uart_get_char(void) {
    // Wait until data is received (RXC0 = 1)
    while (!(UCSR0A & (1 << RXC0))) {
        // wait
    }

    // Read and return received data from UART buffer
    return UDR0;
}