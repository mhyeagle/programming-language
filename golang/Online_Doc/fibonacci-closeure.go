package main

import "fmt"

func fibonacci(x int) func() int {
    f0, f1, f2 = 0, 1, 0
    return func(x int) int {
        if x == 0 {
            return 0
        } else if x == 1 {
            return 1
        } else {

        }
    }
}

func main() {
    f := fibonacci()
    for i := 0; i < 10; i++ {
        fmt.Println(f())
    }

}
