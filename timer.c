#include <avr/io.h>
#include <avr/interrupt.h>

static void (*isr)() = 0;

void timer_init(uint8_t prescale_mask, uint16_t ticks, void (*f)() ) {
	isr = f;
	TCCR1B |= _BV(WGM12);      // CTC mode
	TCCR1B |= (prescale_mask);
	OCR1A   = ticks;
	TIMSK1 |= _BV(OCIE1A);     // enable interrupt
}

ISR(TIMER1_COMPA_vect) {
	isr();
}
