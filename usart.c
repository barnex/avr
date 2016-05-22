#include "usart.h"
#include "led.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>


#define BAUD     57600
#define BAUD_TOL 2
#undef  USE_2X
#include <util/setbaud.h>

#define USART_PORT_DDR DDRD
#define USART_RX_PIN   PIN0
#define USART_TX_PIN   PIN1


// for asynchronous writing
static volatile uint8_t *async_tx_buf = 0;
static volatile uint8_t async_tx_pos = 0;
static volatile uint8_t async_tx_len = 0;
static volatile bool async_tx_busy = false;


void usart_init() {
	// init speed based on BAUD, BAUD_TOL, USE_2X
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
#ifdef USE_2X
	UCSR0A |= _BV(U2X0);
#else
	UCSR0A &= ~(_BV(U2X0));
#endif

	USART_PORT_DDR |= _BV(USART_TX_PIN);  // TX: output
	USART_PORT_DDR &= ~_BV(USART_RX_PIN); // RX: input
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);   // enable RX, TX
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); // 8-bit
}


void usart_write_sync(uint8_t b) {
	// spin while buffer becomes empty and async tx finishes
	while (async_tx_busy || !(UCSR0A & _BV(UDRE0))) {
	}
	UDR0 = b;
}

void usart_write_async(uint8_t *data, uint8_t len) {
	while(async_tx_busy) { // wait for previous operation
	}
	async_tx_buf = data;
	async_tx_pos = 0;
	async_tx_len = len;
	async_tx_busy = true;

	UCSR0B |= _BV(UDRIE0); // enable buffer empty interrupt
}

//UDR0 Empty interrupt service routine
ISR(USART_UDRE_vect) {
	if(async_tx_pos != async_tx_len) {
		UDR0 = async_tx_buf[async_tx_pos];
		async_tx_pos++;
	} else {
		UCSR0B &= ~_BV(UDRIE0); // disable buffer empty interrupt
		async_tx_busy = false;
	}
}


uint8_t usart_read_sync() {
	while ( !(UCSR0A & _BV(RXC0)) ) {
	}
	return UDR0;
}
