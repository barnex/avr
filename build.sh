set -e

rm -f *.hex
avr-gcc -Os -std=c99 -Wall -Werror -mmcu=atmega328p -DF_CPU=16000000L -MMD *.c -o kern
avr-objcopy -O ihex -R .eeprom kern kern.hex
rm -f  *.o kern *.d
