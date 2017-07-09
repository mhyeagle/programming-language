package main

import (
    "fmt"
    "strings"
)

type Vertex struct {
    Lat, Long float64
}

var m map[string]Vertex

func WordCount(s string) map[string]int {
    words := strings.Fields(s)
    map_local := make(map[string]int)
    for _, v := range(words) {
        _, status := map_local[v]
        if status == false {
            map_local[v] = 1
        } else {
            map_local[v] += 1
        }
    }

    return map_local
}

func main() {
    m = make(map[string]Vertex)
    m["Bell"] = Vertex {
        40.6, -17.1,
    }
    fmt.Println(m["Bell"])

    var n = map[string]Vertex {
        "hello": Vertex{
            40, -1,
        },
        "world": Vertex{
            20, -19,
        },
        "miao": {1988, 6}, //omit Vertex
    }
    fmt.Println(n)

    map2 := make(map[string]int)

    map2["a"] = 1
    map2["b"] = 2
    fmt.Println(map2)
    delete(map2, "a")
    fmt.Println(map2)

    v, ok := map2["a"]
    fmt.Printf("v:%d, status:%t\n", v, ok)

    fmt.Println("******")

    fmt.Println("words count: ", WordCount(" hello world hello miao"))
}

