#include "kern.h"
#include "led.h"
#include "spi.h"
#include "timer.h"
#include "usart.h"

#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

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

	for(;;) {
		kprintx(SPSR);
		kprintln(" SPSR.");
		kprintln("SPI write...");
		SPDR = 'A';
		kprintx(SPSR);
		kprintln(" SPSR.");
		kprintx(SPDR);
		kprintln(" SPI data.");
		kprintx(SPSR);
		kprintln(" SPSR.");
		for (uint16_t i = 0; i< 10000; i++) {}
	}

	return 1;
}

