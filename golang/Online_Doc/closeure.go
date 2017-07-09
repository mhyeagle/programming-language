package main

import "fmt"

//匿名函数，可作为闭包。匿名函数是一个‘内联’语句或表达式。匿名函数的优越性在于可直接使用函数内的变量，不必声明

func getSequence() func() int {
	i := 0
	return func() int {
		i += 1
		return i
	}
}

func main() {
	nextNumber := getSequence()

	fmt.Println(nextNumber())
	fmt.Println(nextNumber())
	fmt.Println(nextNumber())

	fmt.Println("***")
	nextNumber_1 := getSequence()
	fmt.Println(nextNumber_1())
	fmt.Println(nextNumber_1())
}
