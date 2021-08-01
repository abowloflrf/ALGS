/*
 * @lc app=leetcode.cn id=2 lang=golang
 *
 * [2] Add Two Numbers
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (40.57%)
 * Likes:    6520
 * Dislikes: 0
 * Total Accepted:    926.5K
 * Total Submissions: 2.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 *
 *
 */
package leetcode_2

type ListNode struct {
	Val  int
	Next *ListNode
}

// @lc code=start

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{}
	head := dummy

	var flag int
	for l1 != nil || l2 != nil {
		sum := 0
		if l1 != nil && l2 != nil {
			sum = l1.Val + l2.Val + flag
			l1 = l1.Next
			l2 = l2.Next
		} else if l1 == nil {
			sum = l2.Val + flag
			l2 = l2.Next
		} else if l2 == nil {
			sum = l1.Val + flag
			l1 = l1.Next
		}

		flag = 0
		if sum >= 10 {
			flag = 1
			sum = sum - 10
		}
		dummy.Next = &ListNode{Val: sum}
		dummy = dummy.Next
	}
	if flag == 1 {
		dummy.Next = &ListNode{Val: 1}
	}
	return head.Next
}

// @lc code=end
