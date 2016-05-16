#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>

// uart_init initializes the UART.
// Baud rate is controlled by the macros:
// 	BAUD, BAUD_TOL, USE_2X
// 	UART_PORT_DDR, UART_RX_PIN, UART_TX_PIN
// Protocol is 8 bits, no parity, 1 stop bit.
void uart_init();

// uart_put_sync writes x to the UART.
// Synchronous write: waits for previous byte to be flushed.
// Does not use interrupts.
// uart_init must be called first.
void uart_put_sync(uint8_t x);

#endif
