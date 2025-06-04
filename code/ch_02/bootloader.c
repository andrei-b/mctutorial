#include <avr/io.h>
#include <avr/boot.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)
#define PAGE_SIZE SPM_PAGESIZE
#define BOOT_TIMEOUT_MS 200

void uart_init() {
    UBRR0H = (UBRR_VALUE >> 8);
    UBRR0L = (uint8_t)UBRR_VALUE;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

uint8_t uart_rx_ready() {
    return UCSR0A & (1 << RXC0);
}

uint8_t uart_read() {
    while (!uart_rx_ready());
    return UDR0;
}

void uart_write(uint8_t c) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

void write_flash_page(uint16_t page_addr, uint8_t *buf) {
    uint16_t i;
    uint16_t word;

    boot_page_erase(page_addr);
    boot_spm_busy_wait();

    for (i = 0; i < PAGE_SIZE; i += 2) {
        word = buf[i] | (buf[i + 1] << 8);
        boot_page_fill(page_addr + i, word);
    }

    boot_page_write(page_addr);
    boot_spm_busy_wait();
    boot_rww_enable();
}

void load_program() {
    uint8_t page_buf[PAGE_SIZE];
    uint16_t page_addr = 0x0000;

    while (1) {
        // Wait for start byte
        uint8_t start = uart_read();
        if (start == 0xFF) {
            for (uint16_t i = 0; i < PAGE_SIZE; ++i)
                page_buf[i] = uart_read();

            write_flash_page(page_addr, page_buf);
            page_addr += PAGE_SIZE;
            uart_write('O');  // Acknowledge
        } else if (start == 0x00) {
            uart_write('D');  // Done
            break;
        }
    }
}

void jump_to_application() {
    cli();
    asm volatile ("jmp 0x0000");
}

int main(void) {
    uart_init();

    // Boot delay waiting for serial upload
    uint16_t timeout = BOOT_TIMEOUT_MS;
    while (timeout--) {
        if (uart_rx_ready()) {
            load_program();
            break;
        }
        _delay_ms(1);
    }

    jump_to_application();
}
