package main

import "fmt"

// Given two strings s and t which consist of only lowercase letters.
//
// String t is generated by random shuffling string s and then add one more letter at a random position.
//
// Find the letter that was added in t.
//
// Example:
//
// Input:
// s = "abcd"
// t = "abcde"
//
// Output:
// e
//
// Explanation:
// 'e' is the letter that was added.

// xor
func findTheDifference(s string, t string) byte {
	var extra rune
	for _, r := range s {
		extra ^= r
	}
	for _, r := range t {
		extra ^= r
	}
	return byte(extra)
}

func main() {
	fmt.Println(findTheDifference("abcd", "abced"))
}
