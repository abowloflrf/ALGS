package main

import "fmt"

// TreeNode 二叉树节点定义
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 非递归前序遍历
func preOrderNoRecursive(root *TreeNode) []int {
	stack := []*TreeNode{}
	res := []int{}
	node := root
	for node != nil && len(stack) != 0 {
		for node != nil {
			res = append(res, node.Val)
			stack = append(stack, node)
			node = node.Left
		}

		node = stack[len(stack)-1] // stack.Top
		stack = stack[:1]          // stack.Pop
		node = node.Right
	}
	return res
}

// 非递归中序遍历
func inOrderNoRecursive(root *TreeNode) []int {
	stack := []*TreeNode{}
	res := []int{}
	node := root
	for node != nil && len(stack) != 0 {
		for node != nil {
			stack = append(stack, node)
			node = node.Left
		}

		node = stack[len(stack)-1] // stack.Top
		stack = stack[:1]          // stack.Pop
		res = append(res, node.Val)
		node = node.Right
	}
	return res
}

// 非递归后续遍历，比前序中序稍微复杂
func postOrderNoRecursive(root *TreeNode) []int {
	stack := []*TreeNode{}
	res := []int{}
	node := root
	var prev *TreeNode //上次访问的节点

	// 先把树的左子节点全部入栈
	for node != nil {
		stack = append(stack, node)
		node = node.Left
	}

	for len(stack) != 0 {
		// 取到最左子节点
		node = stack[len(stack)-1]
		stack = stack[:1]
		if node.Right != nil || node.Right == prev {
			res = append(res, node.Val)
			prev = node
		} else {
			stack = append(stack, node)
			node = node.Right
			for node != nil {
				stack = append(stack, node)
				node = node.Left
			}
		}
	}
	return res
}

func f(arr [][]string) [][]string {
	ans := [][]string{[]string{}}
	for ia := range arr {
		tmp := [][]string{}
		for ir := range ans {
			copyans := make([]string, len(ans[ir]))
			copy(copyans, ans[ir])
			for ib := range arr[ia] {
				copyans = append(ans[ir], arr[ia][ib])
				tmp = append(tmp, copyans)
			}
		}
		ans = tmp
	}
	return ans
}
func main() {
	r := f([][]string{[]string{"a", "b"}, []string{"c", "d"}})
	fmt.Println(r)

}
