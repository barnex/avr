#include "kern.h"
#include "usart.h"

#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

int main() {

	usart_init();
	kprintln("\nUSART initialized");

	kprintln("enabling interrupts");
	sei();

	kprintln("This is a sync write.");
	usart_write_async((uint8_t*)"Hello async usart!\n", 19);
	kprintln("This is another sync write.");
	usart_write_async((uint8_t*)"Bye async usart!\n", 18);
	kprintln("This is yet one more sync write.");

	for(;;) {
		usart_write_sync(usart_read_sync());
	}

	return 1;
}

