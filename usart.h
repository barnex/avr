#ifndef _USART_H_
#define _USART_H_

#include <stdint.h>

// usart_init initializes the USART.
// Baud rate is controlled by the macros:
// 	BAUD, BAUD_TOL, USE_2X
// 	USART_PORT_DDR, USART_RX_PIN, USART_TX_PIN
// Protocol is 8 bits, no parity, 1 stop bit.
void usart_init();

// usart_write_sync writes x to the USART, synchronously.
// usart_init must be called first. Does not use interrupts.
void usart_write_sync(uint8_t x);

// usart_write_async writes len bytes from data to the USART, asynchronously.
// usart_init must be called first and interrupts must be enabled.
void usart_write_async(uint8_t *data, uint8_t len);

uint8_t usart_read_sync();

#endif
