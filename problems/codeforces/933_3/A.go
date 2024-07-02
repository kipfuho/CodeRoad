package main

import "fmt"

var arr1 [100]int
var arr2 [100]int
var n, m, k int

func inputProblemA() {
	fmt.Scan(&n, &m, &k)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr1[i])
	}
	for i := 0; i < m; i++ {
		fmt.Scan(&arr2[i])
	}
}

func solveProblemA() {
	countPair := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if arr1[i]+arr2[j] <= k {
				countPair++
			}
		}
	}
	fmt.Println(countPair)
}

func main() {
	var t int
	fmt.Scanln(&t)
	for i := 1; i <= t; i++ {
		inputProblemA()
		solveProblemA()
	}
}
