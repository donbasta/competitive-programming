package main

import (
	"fmt"
)

const A = 26

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func Solve() {
	var keyboard, word string
	fmt.Scan(&keyboard, &word)
	pos := make([]int, A)
	for idx, c := range keyboard {
		pos[c-'a'] = idx
	}
	ret := 0
	for i := 1; i < len(word); i++ {
		ret += abs(pos[word[i]-'a'] - pos[word[i-1]-'a'])
	}
	fmt.Println(ret)
}

func main() {
	var TC int
	fmt.Scanln(&TC)
	for i := 0; i < TC; i++ {
		Solve()
	}
}
