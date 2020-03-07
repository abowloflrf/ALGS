package leetcode

func twoSum(nums []int, target int) []int {
	m := map[int]int{}
	for i, value := range nums {
		v, ok := m[target-value]
		if ok && v != i {
			return []int{v, i}
		}
		m[value] = i
	}
	return nil
}
