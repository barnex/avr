package main

import (
	"log"
	"os"
	"io"
)

// #include "ttycfg.h"
import "C"

const (
	B50     = C.B50
	B75     = C.B75
	B110    = C.B110
	B134    = C.B134
	B150    = C.B150
	B200    = C.B200
	B300    = C.B300
	B600    = C.B600
	B1200   = C.B1200
	B1800   = C.B1800
	B2400   = C.B2400
	B4800   = C.B4800
	B9600   = C.B9600
	B19200  = C.B19200
	B38400  = C.B38400
	B57600  = C.B57600
	B115200 = C.B115200
	B230400 = C.B230400
)

func main() {
		f, err := os.OpenFile("/dev/ttyUSB0", os.O_RDWR|os.O_SYNC, 0666) // os.O_NOCTTY|
	if err != nil {
		log.Fatal(err)
	}
	defer f.Close()

	_, err = C.initTTY(C.int(f.Fd()), B57600)
	if err != nil {
		log.Fatal(err)
	}

	go func(){log.Fatal(io.Copy(f, os.Stdin))}()
	go func(){log.Fatal(io.Copy(os.Stdout, f))}()

	select{}
}
