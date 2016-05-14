#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>


int main (void) {

	DDRB = 0xFF; // set PORTB for output
	DDRD = 0xFF; // set PORTD for output

	uint8_t position = 0x01;
	bool go_left = true;

	for (;;) {

		PORTB = position;
		PORTD = position;

		if (go_left) {
			position <<= 1;
		} else {
			position >>= 1;
		}

		if (position == 1) {
			go_left = true;
		}
		if (position == 1<<7) {
			go_left = false;
		}

		_delay_ms(100);
	}

	return 1;
}
