#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>

// usart_init initializes the UART.
// Baud rate is controlled by the macros:
// 	BAUD, BAUD_TOL, USE_2X
// 	UART_PORT_DDR, UART_RX_PIN, UART_TX_PIN
// Protocol is 8 bits, no parity, 1 stop bit.
void usart_init();

// usart_write_sync writes x to the UART.
// Synchronous write: waits for previous byte to be flushed.
// Does not use interrupts.
// usart_init must be called first.
void usart_write_sync(uint8_t x);

#endif
