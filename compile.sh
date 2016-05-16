set -e
set -v

for f in "$@"; do
	rm -f $f.hex
	avr-gcc -c -Os -std=c99 -Wall -Werror -mmcu=atmega328p -DF_CPU=16000000L -MMD $f.c -o $f.o
	avr-gcc -mmcu=atmega328p $f.o -o $f
	avr-objcopy -O ihex -R .eeprom $f $f.hex
done;
