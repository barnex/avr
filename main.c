#include "kern.h"
#include "led.h"
#include "timer.h"
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

	kprintx(1);
	kprintx(127);

	timer_init(TIMER_PRESCALE_1024, 16000, led_toggle);


	for(;;) {
		uint8_t cmd;
		do {
			cmd = usart_read_sync();
		} while(cmd == 0);
		uint8_t val = usart_read_sync();
	}

	return 1;
}

