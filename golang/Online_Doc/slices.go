package main

import (
	"fmt"
	"math"
    "github.com/golang/tour/blob/master/pic"
)

func Pic(dx, dy int) [][]uint8 {
    var arr [][]uint8
    for i := 0; i < dx; i++ {
        for j := 0; j < dy; j++ {
            arr[i][j] = j;
        }
    }

    return arr
}

func main() {
    pic.Show(Pic)
}
