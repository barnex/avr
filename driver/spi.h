#ifndef _SPI_H_
#define _SPI_H_

void spi_init_master();

void spi_init_slave();

uint8_t spi_tx(uint8_t data);

#endif
