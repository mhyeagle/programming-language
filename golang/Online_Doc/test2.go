package main

import (
	"fmt"
	"math"
	"runtime"
	"time"
)

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim { //if 语句可以类似 for 一样前置一个简单语句
		return v
	} else {
		fmt.Println("hello")
	}
	return lim
}

func main() {
	sum := 0
	for i := 1; i < 10; i++ {
		sum += i
	}
	fmt.Println(sum)

	for sum < 100 { //for 是 Go 的 while
		sum++
	}

	//for {} 不加条件是死循环
	fmt.Println(sum)

	fmt.Println(
		pow(3, 2, 10),
		pow(3, 3, 10),
	)

	fmt.Println("Go run on")
	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X")
	case "linux":
		fmt.Println("linux")
	default:
		fmt.Println("%s", os)
	}

	fmt.Println("when is monday ?")
	today := time.Now().Weekday()
	fmt.Println(time.Monday)
	fmt.Println("today+1", today+1)
	fmt.Println("today+2", today+2)
	switch time.Monday {
	case today + 0:
		fmt.Println("today")
	case today + 1:
		fmt.Println("tomorrow")
	case today + 2:
		fmt.Println("two days later")
	default:
		fmt.Println("too far awary")
	}

	//使用下面的switch可替代大量的if-then-else链
	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("good morning")
	case t.Hour() < 17:
		fmt.Println("good afternoon")
	default:
		fmt.Println("good evening")
	}

}
