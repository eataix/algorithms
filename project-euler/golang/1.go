package main

import "fmt"

func main() {
	var sum uint64 = 0

	for i := 3; i < 1000; i++ {
		if i%3 == 0 || i%5 == 0 {
			sum += uint64(i)
		}
	}
	fmt.Println(sum)
}
