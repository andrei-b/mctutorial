#ifndef UART
#define UART

#include <stdint-gcc.h>
#include <avr/io.h>

/* uart.h - UART communication functions for AVR microcontrollers
 * This header file provides functions to initialize UART, send strings, characters,
 * and hexadecimal or decimal values over UART.
 */

/* uart_init - Initializes the UART with the specified baud rate.
 * @baud: The desired baud rate for UART communication.
 */

void uart_init(uint32_t baud);
void uart_send_char(char c);
char uart_get_char(void);


#endif