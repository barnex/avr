#include "driver/debug.h"
#include "driver/led.h"
#include "driver/spi.h"
#include "driver/timer.h"
#include "driver/usart.h"

#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

//static volatile int dump;

int main() {

	led_on();
	usart_init();
	debugln("\nUSART initialized");

	//spi_init_slave();
	//debugln("SPI slave");

	spi_init_master();
	debugln("SPI master");

	//debugln("enabling interrupts");
	//sei();


	for(int i=0; i<5; i++) {

		debugx(spi_tx(42)); debugln(" spi_tx");
		//debugx(SPSR); debugln(" SPSR.");
		//SPDR = 'A';
		//debugx(SPSR); debugln(" SPSR.");

		//debugln("delay");
		//_delay_ms(1000);

		//SPSR &= ~_BV(SPIF);

	}

	for (;;){}

	return 1;
}

