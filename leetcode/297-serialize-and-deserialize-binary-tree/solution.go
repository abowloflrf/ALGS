/*
 * @lc app=leetcode.cn id=297 lang=golang
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (55.65%)
 * Likes:    620
 * Dislikes: 0
 * Total Accepted:    98K
 * Total Submissions: 176K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1,2]
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 *
 *
 */
package leetcode_297

import (
	"fmt"
	"strconv"
	"strings"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	if root == nil {
		return "[]"
	}
	q := []*TreeNode{}
	r := []string{}
	q = append(q, root)
	for len(q) > 0 {
		n := q[0]
		q = q[1:]
		if n == nil {
			r = append(r, "null")
		} else {
			r = append(r, strconv.Itoa(n.Val))
			q = append(q, n.Left)
			q = append(q, n.Right)
		}
	}
	res := strings.Join(r, ",")
	return fmt.Sprintf("[%s]", res)
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	tmp := data[1 : len(data)-1]
	d := strings.Split(tmp, ",")
	if len(d) == 0 || (len(d) == 1 && d[0] == "") {
		return nil
	}

	v, _ := strconv.Atoi(d[0])
	root := &TreeNode{Val: v}
	q := []*TreeNode{root}

	idx := 1
	for idx < len(d) {
		node := q[0]
		q = q[1:]
		leftStr := d[idx]
		rightStr := d[idx+1]
		if leftStr != "null" {
			v, _ := strconv.Atoi(leftStr)
			node.Left = &TreeNode{Val: v}
			q = append(q, node.Left)
		}
		if rightStr != "null" {
			v, _ := strconv.Atoi(rightStr)
			node.Right = &TreeNode{Val: v}
			q = append(q, node.Right)
		}
		idx += 2
	}
	return root
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor();
 * deser := Constructor();
 * data := ser.serialize(root);
 * ans := deser.deserialize(data);
 */
// @lc code=end
