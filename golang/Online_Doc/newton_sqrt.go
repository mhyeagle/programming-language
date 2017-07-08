package main

import (
    "fmt"
)

func sqrt(x float64) float64 {
    start := 10.0
    temp := 0.0
    for i := 0; i < 20; i++ {
        temp = start - (start*start - x) / (2*start)
        start = temp
        fmt.Println("temp: ", temp)
    }

    return start
}

func main() {
    fmt.Println("num_f: ", sqrt(625))
    fmt.Println("***")
    fmt.Println("num_f: ", sqrt(19))
    fmt.Println("***")
    fmt.Println("num_f: ", sqrt(768))

}
