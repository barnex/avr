#include <avr/io.h>
#include <util/delay.h>

int main (void) {

	DDRB = 0xFF; // set PORTB for output

	for (;;) {

		PORTB = 0xFF;
		for(unsigned int counter = 0; counter != 200; counter++) {
			_delay_loop_2(1000);
			counter++;
		}

		PORTB = 0x00;
		for(unsigned int counter = 0; counter != 200; counter++) {
			_delay_loop_2(1000);
		}
	}

	return 1;
}
