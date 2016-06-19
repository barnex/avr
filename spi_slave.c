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

	spi_init_slave();
	debugln("SPI slave");

	for(;;) {
		debugx(spi_tx(43)); debugln(" spi_tx");
	}

	return 1;
}

