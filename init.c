#include "kern.h"

#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#define LEN_MSG 15
char msg[LEN_MSG] = "Hello, world!\n";

int main() {

	uart_init();
	kprintln("\nUART initialized");

	UCSR0B |= _BV(UDRIE0); // enable buffer empty interrupt

	kprintln("enabling interrupts");
	sei();

	for (;;) {
	}

	return 1;
}

//UDR0 Empty interrupt service routine
ISR(USART_UDRE_vect) {
	UDR0 = 'B';
	_delay_ms(100);
	return;
}
