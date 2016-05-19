#include "ttycfg.h"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

void initTTY(int fd, int baud) {

	if(!isatty(fd)) {
		errno = ENOTTY;
		return;
	}

	// setup tty
	struct termios config;
	if(tcgetattr(fd, &config) < 0) {
		return;
	}
	cfmakeraw(&config);
	config.c_cflag &= ~(CSIZE | PARENB);
	config.c_cflag |= CS8;
	config.c_cc[VMIN]  = 128; // buffer
	config.c_cc[VTIME] = 1;   // return as quickly as possible

	// communication speed
	if(cfsetispeed(&config, baud) < 0 || cfsetospeed(&config, baud) < 0) {
		return;
	}

	if(tcsetattr(fd, TCSANOW, &config) != 0) {
		return;
	}
	
	errno = 0;
	return;
}
