#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>

void uart_init();

void uart_put_sync(uint8_t x);

#endif
