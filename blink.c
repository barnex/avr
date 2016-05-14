#include <avr/io.h>
#include <util/delay.h>

int main (void) {

	DDRB = 0xFF; // set PORTB for output
	DDRD = 0xFF; // set PORTD for output

	for (;;) {

		for(unsigned int counter = 0; counter != 400; counter++) {
			_delay_loop_2(1000);
			counter++;
		}

		PORTB = PORTB << 1;
		PORTD = PORTD << 1;
		if (PORTD == 0) {
			PORTD=1;
		}
		if (PORTB == 0) {
			PORTB=1;
		}
	}

	return 1;
}
