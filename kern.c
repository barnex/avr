#include "kern.h"
#include "led.h"

#include <avr/interrupt.h>
#include <util/delay.h>


void panic(){
	cli();
	for(;;){
		led_off();
		_delay_ms(200);
		led_on();
		_delay_ms(200);
	}
}
