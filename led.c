#include "led.h"

#include <avr/io.h>

#define LED_PORT     PORTB
#define LED_PORT_DDR DDRB
#define LED_PIN      PIN5

inline void led_on() {
	LED_PORT_DDR |= _BV(LED_PIN);
	LED_PORT |= _BV(LED_PIN);
}

inline void led_off() {
	LED_PORT &= ~_BV(LED_PIN);
}
