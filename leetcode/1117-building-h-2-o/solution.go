package main

import (
	"fmt"
	"os"
	"runtime/trace"
	"sync"
	"time"
)

var (
	lock   sync.Mutex
	countH int
	countO int
)

func hydrogen() {
	lock.Lock()
	defer lock.Unlock()
	countH++
}

func oxygen() {
	lock.Lock()
	defer lock.Unlock()
	countO++
}

func H2O() {
	for {
		lock.Lock()
		if countH >= 2 && countO >= 1 {
			countH -= 2
			countO--
			fmt.Printf("H2O, H[%d] O[%d]\n", countH, countO)
		}
		lock.Unlock()
	}
}

func main() {
	_ = trace.Start(os.Stderr)
	defer trace.Stop()

	n := 20
	worker := 3
	for i := 0; i < n; i++ {
		go hydrogen()
		go hydrogen()
		go oxygen()
	}
	for i := 0; i < worker; i++ {
		go H2O()
	}
	time.Sleep(1 * time.Millisecond)
}
