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
	}

	return 1;
}

