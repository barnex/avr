#include "kern.h"
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


void kprintln(char* str) {
	while(*str != 0) {
		usart_write_sync(*str);
		str++;
	}
	usart_write_sync('\n');
}
