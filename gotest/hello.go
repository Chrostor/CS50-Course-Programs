package main

import (
	"flag"
	"fmt"
)

func main() {
	port := flag.Int("p", 1234, "The port to listen on")
	flag.Parse()
	
	fmt.Printf("port is %d and type %T\n", *port, *port)
}
