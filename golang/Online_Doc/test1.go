package main

import (
    "fmt"
    "math"
)

func add(x, y int) int {
    return x + y
}

func swap(x, y string) (string, string) {
    return y, x
}

func split(sum int) (x, y int) {
    x = sum * 4 / 9
    y = sum - x
    return
}

var var1 string

var (
    flag bool = false
    max uint64 = 1<<64 -1
)

const Pi = 3.14

func main() {
    fmt.Println(math.Pi)
    fmt.Println(add(1, 2))
    a, b := swap("hello", "world")
    fmt.Println(a, b)
    fmt.Println(split(17))

    var1 = "var1_hello"
    fmt.Println(var1)

    var i int
    j := 2 //只能使用在函数内
    fmt.Println(i, j)

    const f = "%T(%v)\n"
    fmt.Printf(f, flag, flag)
    fmt.Printf(f, max, max)

    x := 3.14
    y := int(x)
    //var z int = x 类型需要显示转换，没有隐士转换
    fmt.Println(x, y)

    //const a := 1

}

