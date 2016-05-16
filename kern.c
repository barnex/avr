#include "kern.h"
#include "led.h"

#include <avr/interrupt.h>
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
		uart_put_sync(*str);
		str++;
	}
	uart_put_sync('\n');
}
