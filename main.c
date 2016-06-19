#include "kern.h"
#include "led.h"
#include "spi.h"
#include "timer.h"
#include "usart.h"

#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

//static volatile int dump;

int main() {

	led_on();
	usart_init();
	kprintln("\nUSART initialized");

	//spi_init_slave();
	//kprintln("SPI slave");

	spi_init_master();
	kprintln("SPI master");

	//kprintln("enabling interrupts");
	//sei();


	for(int i=0; i<3; i++) {

		kprintx(SPSR); kprintln(" SPSR.");
		SPDR = 'A';
		kprintx(SPSR); kprintln(" SPSR.");

		kprintln("delay");
		_delay_ms(1000);

		//SPSR &= ~_BV(SPIF);

	}

	for (;;){}

	return 1;
}

