#include "debug.h"
#include "led.h"
#include "usart.h"

#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>


void panic() {
	cli();
	for(;;) {
		led_toggle();
		_delay_ms(200);
	}
}


void debugln(char* str) {
	while(*str != 0) {
		usart_write_sync(*str);
		str++;
	}
	usart_write_sync('\n');
}

static uint8_t hex_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void debugx(int n) {
	usart_write_sync('0');
	usart_write_sync('x');
	usart_write_sync(hex_digits[(n & 0xF000) >> 12]);
	usart_write_sync(hex_digits[(n & 0x0F00) >>  8]);
	usart_write_sync(hex_digits[(n & 0x00F0) >>  4]);
	usart_write_sync(hex_digits[(n & 0x000F) >>  0]);
}
