set -e
set -v

rm -f blink.hex
avr-gcc -c -Os -std=c99 -Wall -Werror -mmcu=atmega328p -DF_CPU=8000000L -MMD   blink.c -o blink.o
avr-gcc -mmcu=atmega328p blink.o -o blink
avr-objcopy -O ihex -R .eeprom blink blink.hex
