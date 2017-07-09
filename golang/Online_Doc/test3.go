package main

import (
	"fmt"
)

type Vertex struct {
	X int
	Y int
}

func main() {
	fmt.Println(Vertex{1, 2})
	v := Vertex{3, 4}
	p := &v
	p.X = 19 //指向结构体的指针通过 . 来访问结构体成员
	fmt.Println(v)

	v1 := Vertex{X: 99}
	fmt.Println(v1)

	var arr [3]string
	arr[0] = "hello"
	arr[1] = "world"
	fmt.Println(arr)

	q := []int{11, 12, 13, 14}
	fmt.Println("q == ", q)
	for i := 0; i < len(q); i++ {
		fmt.Printf("q[%d] = %d\n", i, q[i])
	}
	fmt.Println("q[1:3] = ", q[1:3])

	s := make([]int, 0, 5)
	fmt.Printf("s len:[%d], capacity:[%d]\n", len(s), cap(s))
	fmt.Println(s)
	s = append(s, 111)
	s = append(s, 112)
	fmt.Println(s)

	for i, v := range s {
		fmt.Printf("s[%d] = %d\n", i, v)
	}
	for _, value := range s { //可以通过 _ 来忽略序号或值
		fmt.Printf("%d\n", value)
	}

}
