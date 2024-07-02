package main

import "fmt"

var arr [][]int

func dfs(u int, pre int) {
	if arr[u] == nil {
		return
	}
	for _, v := range arr[u] {
		fmt.Println(v)
	}
}

func main() {
	var m, e1, e2 int
	arr = make([][]int, 5)
	fmt.Scanln(&m)
	for i := 0; i < m; i++ {
		fmt.Scanln(&e1, &e2)
		// wtf???
		arr[e1] = append(arr[e1], e2)
		arr[e2] = append(arr[e2], e1)
	}
	dfs(1, 0)
}
