./compile.sh && \
avrdude -C avrdude.conf -v -p atmega328p -c arduino -P /dev/ttyUSB0 -b 57600 -D -U flash:w:kern.hex:i