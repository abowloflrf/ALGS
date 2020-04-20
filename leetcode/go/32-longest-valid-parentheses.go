package leetcode

func longestValidParentheses(s string) int {
	stack := []int{}
	ans := 0
	for i, v := range s {
		if len(stack) != 0 && v == ')' && s[stack[len(stack)-1]] == '(' {
			stack = stack[:len(stack)-1]
			if len(stack) == 0 {
				ans = i + 1
			} else {
				if i-stack[len(stack)-1] > ans {
					ans = i - stack[len(stack)-1]
				}
			}
		} else {
			stack = append(stack, i)
		}
	}
	return ans
}
