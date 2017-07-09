package main

import (
	"fmt"
	"math"
)

func compute(fn func(float64, float64) float64) float64 {
	return fn(3, 4)
}

func adder() func(int) int {
	sum := 0
	return func(x int) int {
		sum += x
		return sum
	}
}

func main() {
	func1 := func(x, y float64) float64 {
		return math.Sqrt(x*x + y*y)
	}
	fmt.Println(func1(10, 20))

	fmt.Println(compute(func1))
	fmt.Println(compute(math.Pow))

	fmt.Println("******")
	func_a, func_b := adder(), adder()
	for i := 0; i < 10; i++ {
		fmt.Println(
			func_a(i),
			func_b(-2*i),
		)
	}
}
