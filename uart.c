#define BAUD     57600
#define BAUD_TOL 2
#undef  USE_2X

#define UART_PORT_DDR DDRD
#define UART_RX_PIN   PIN0
#define UART_TX_PIN   PIN1

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <util/delay.h>
#include <util/setbaud.h>


void uart_init() {
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
#ifdef USE_2X
	UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

	UART_PORT_DDR |= _BV(UART_TX_PIN); // TX: out
	UART_PORT_DDR &= ~_BV(UART_RX_PIN); // RX: in
	UCSR0B = _BV(RXEN0) | _BV(TXEN0); // enable RX, TX

	UCSR0C = 0;
	UCSR0C |= _BV(UCSZ01) | _BV(UCSZ00); // 8-bit
}


void uart_write(uint8_t b) {
	// busy wait for buffer to become empty
	while (!(UCSR0A & _BV(UDRE0)));
	UDR0 = b;
}


#define LEN_MSG 15
char msg[LEN_MSG] = "Hello, world!\n";

int main() {

	uart_init();

	for (;;) {
		for (uint8_t i=0; i<LEN_MSG; i++) {
			uart_write(msg[i]);
		}
		_delay_ms(1000);
	}

	return 1;
}

