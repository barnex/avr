#ifndef _KERN_H_
#define _KERN_H_

#include "led.h"
#include "uart.h"

void panic();

void kprintln(char* str);

void uart_write_async(uint8_t *x, uint8_t len);

#endif
