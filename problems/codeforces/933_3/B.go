package main

import "fmt"

var n int
var arr [200000]int

func solveProblemB() {
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	valid := true
	for i := 0; i < (n - 1); i++ {
		if arr[i] == 0 {
			continue
		}
		if arr[i] < 0 {
			valid = false
			break
		}
		if 2*arr[i] > arr[i+1] {
			valid = false
			break
		}
		arr[i+1] -= 2 * arr[i]
		if i+2 < n {
			arr[i+2] -= arr[i]
		}
	}
	if valid {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		solveProblemB()
	}
}
