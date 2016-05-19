// catty redirects stdin/stdout to a TTY device. Usage:
// 	catty -baud 9600 /dev/ttyUSB0
package main

import (
	"flag"
	"io"
	"log"
	"os"
)

// #include "ttycfg.h"
import "C"

var baudCodes = map[int]int{
	50:     C.B50,
	75:     C.B75,
	110:    C.B110,
	134:    C.B134,
	150:    C.B150,
	200:    C.B200,
	300:    C.B300,
	600:    C.B600,
	1200:   C.B1200,
	1800:   C.B1800,
	2400:   C.B2400,
	4800:   C.B4800,
	9600:   C.B9600,
	19200:  C.B19200,
	38400:  C.B38400,
	57600:  C.B57600,
	115200: C.B115200,
	230400: C.B230400,
}

var baud = flag.Int("baud", 57600, "Baud rate")

func main() {
	log.SetFlags(0)
	flag.Parse()

	if flag.NArg() != 1 {
		log.Fatal("Need one file")
	}

	baudCode := baudCodes[*baud]
	if baudCode == 0 {
		log.Fatal("Invalid baud rate:", *baud)
	}
	f, err := os.OpenFile(flag.Arg(0), os.O_RDWR|os.O_SYNC, 0666)
	if err != nil {
		log.Fatal(err)
	}
	defer f.Close()

	_, err = C.initTTY(C.int(f.Fd()), C.int(baudCode))
	if err != nil {
		log.Fatal(err)
	}

	go func() { log.Fatal(io.Copy(f, os.Stdin)) }()
	go func() { log.Fatal(io.Copy(os.Stdout, f)) }()

	select {}
}
