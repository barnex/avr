#include "led.h"
#include "uart.h"

#include <stdint.h>
#include <util/delay.h>

#define LEN_MSG 15
char msg[LEN_MSG] = "Hello, world!\n";

int main() {

	uart_init();

	for (;;) {
		led_on();
		for (uint8_t i=0; i<LEN_MSG; i++) {
			uart_put_sync(msg[i]);
		}
		led_off();
		_delay_ms(1000);
	}

	return 1;
}
