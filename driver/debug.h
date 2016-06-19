#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdint.h>

// panic disables interrupts and goes into an infinite loop,
// rapidly blinking the onboard LED to indicate a fatal error condition.
void panic();

// debugln writes a string to the UART for debugging. A newline is appended.
// The implementation is synchronous and works without using interrupts.
void debugln(char* str);

void debugx(int n);

#endif
