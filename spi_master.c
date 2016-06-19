#include "driver/debug.h"
#include "driver/led.h"
#include "driver/spi.h"
#include "driver/timer.h"
#include "driver/usart.h"

#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

int main() {

	led_on();
	usart_init();
	debugln("\nUSART initialized");

	spi_init_master();
	debugln("SPI master");

	for(int i=0; i<5; i++) {
		debugx(spi_tx(42)); debugln(" spi_tx");
	}

	for (;;){}

	return 1;
}

