#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB5

int main(void) {
    // Set PB5 (pin 13 on Arduino Uno) as output
    DDRB |= (1 << LED_PIN);

    while (1) {
        // Toggle the LED
        PORTB ^= (1 << LED_PIN);

        // Delay for ~1 second
        _delay_ms(1000);
    }
}
