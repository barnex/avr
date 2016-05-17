#include "kern.h"
#include "usart.h"

#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#define LEN_MSG 15
char msg[LEN_MSG] = "Hello, world!\n";

int main() {

	usart_init();
	kprintln("\nUSART initialized");

	kprintln("enabling interrupts");
	sei();

	for (;;) {
		kprintln("This is a sync write.");
		usart_write_async((uint8_t*)"Hello async usart!\n", 19);
		kprintln("This is another sync write.");
		usart_write_async((uint8_t*)"Bye async usart!\n", 18);
		kprintln("This is yet one more sync write.");
		_delay_ms(1000);
	}

	return 1;
}

