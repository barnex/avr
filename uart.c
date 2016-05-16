#define BAUD     57600
#define BAUD_TOL 2
#undef  USE_2X

#define UART_PORT_DDR DDRD
#define UART_RX_PIN   PIN0
#define UART_TX_PIN   PIN1
#include "uart.h"

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <util/delay.h>
#include <util/setbaud.h>


void uart_init() {
	// init speed based on BAUD, BAUD_TOL, USE_2X
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
#ifdef USE_2X
	UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

	UART_PORT_DDR |= _BV(UART_TX_PIN);  // TX: output
	UART_PORT_DDR &= ~_BV(UART_RX_PIN); // RX: input
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);   // enable RX, TX
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); // 8-bit
}


void uart_put_sync(uint8_t b) {
	// spin while buffer becomes empty
	while (!(UCSR0A & _BV(UDRE0))){
	}
	UDR0 = b;
}

