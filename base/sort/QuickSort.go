package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func partition(arr []int, lo, hi int) int {
	// 选择最后一位为基准数pivot
	pivot := arr[hi]
	idx := lo
	for j := lo; j < hi; j++ {
		// 比基准数小则交换位置
		if arr[j] < pivot {
			arr[idx], arr[j] = arr[j], arr[idx]
			idx = idx + 1 // idx记录的是换到了哪一位
		}
	}
	// 换完之后将基准数放到最后换完的下一个位置，这样在基准数前面的数都比它小，在后面的都比它大
	arr[idx], arr[hi] = arr[hi], arr[idx]
	return idx
}

func quickSort(arr []int, lo, hi int) {
	if lo < hi {
		p := partition(arr, lo, hi)
		quickSort(arr, lo, p-1)
		quickSort(arr, p+1, hi)
	}
}

func quickSort2(arr []int) []int {
	if len(arr) < 2 {
		return arr
	}
	left := 0
	pivot := len(arr) - 1
	for i := range arr {
		if arr[i] < arr[pivot] {
			arr[i], arr[left] = arr[left], arr[i]
			left++
		}
	}
	arr[left], arr[pivot] = arr[pivot], arr[left]

	quickSort2(arr[:left])
	quickSort2(arr[left+1:])
	return arr
}

func generateArr(size int) []int {
	slice := make([]int, size)
	for i := 0; i < size; i++ {
		slice[i] = rand.Intn(1000000) % 1000000
	}
	return slice
}

func main() {
	rand.Seed(time.Now().UnixNano())

	arrSize := 1000000
	arr0 := generateArr(arrSize)
	arr1 := make([]int, arrSize)
	arr2 := make([]int, arrSize)
	copy(arr1, arr0)
	copy(arr2, arr0)

	now := time.Now()
	sort.Ints(arr0)
	fmt.Println("std sort: ", time.Since(now))

	now = time.Now()
	quickSort(arr1, 0, len(arr1)-1)
	fmt.Println("sort1 sort: ", time.Since(now))

	now = time.Now()
	quickSort2(arr2)
	fmt.Println("sort2 sort: ", time.Since(now))

}
