package main

import (
	"fmt"
	"math"
)

type Vertex struct {
	X, Y float64
}

func (v *Vertex) Mod() {
	v.X = v.X * 2
}

func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func main() {
	v := Vertex{3, 4}
	fmt.Println(v.Abs())
	fmt.Println(v.X)
	v.Mod()
	fmt.Println(v.X)
	fmt.Println("X:", v.X)
	fmt.Printf("X: %f\n", v.X)
}
