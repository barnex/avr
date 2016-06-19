#include <avr/io.h>
#include <avr/interrupt.h>
#include "led.h"

#define SPI_F_4   ((0 << SPR1) | (0 << SPR0))
#define SPI_F_16  ((0 << SPR1) | (1 << SPR0))
#define SPI_F_64  ((1 << SPR1) | (0 << SPR0))
#define SPI_F_128 ((1 << SPR1) | (1 << SPR0))

#define SPI_PORT     PORTB
#define SPI_PORT_DDR DDRB
#define SPI_SS_N_PIN   PIN2
#define SPI_MOSI_PIN PIN3
#define SPI_MISO_PIN PIN4
#define SPI_SCK_PIN  PIN5

void spi_init_master() {

	SPI_PORT_DDR = _BV(SPI_MOSI_PIN) | _BV(SPI_SCK_PIN) | _BV(SPI_SS_N_PIN);	 // enable output
	//SPCR = _BV(SPE) | _BV(MSTR) | SPI_F_64; // | _BV(SPIE);
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	SPI_PORT &=~ _BV(SPI_SS_N_PIN); // TODO: not

	// SPCR
	// _BV: SPIE // interrupt enable
	// 	SPE // spi enable
	// 	DORD // data order : 0 = MSB first
	// 	MSTR // 1 = master
	// 	CPOL // clock polarity: 0 = idle = low
	// 	CPHA // clock phase 1 = leading
	// 	SPR1, SPR0: clock rate
	// SPSR
	// 	_BV: SPIF: interrupt flag
	// 	WCOL: write collision flag
	// 	SPI2x
	// SPDR
}

void spi_init_slave() {
	SPI_PORT_DDR = _BV(SPI_MISO_PIN);
	SPCR = _BV(SPE);
}

uint8_t spi_tx(uint8_t data) {
    SPDR = data;
    while(!(SPSR & (_BV(SPIF)) ));
    return SPDR ;
}

//ISR(SPI_STC_vect) {
//	
//}
