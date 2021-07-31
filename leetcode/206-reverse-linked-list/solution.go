/*
 * @lc app=leetcode.cn id=206 lang=golang
 *
 * [206] Reverse Linked List
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (72.05%)
 * Likes:    1866
 * Dislikes: 0
 * Total Accepted:    623.5K
 * Total Submissions: 865.4K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: [2,1]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 *
 *
 *
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
 *
 */

package leetcode_206

type ListNode struct {
	Val  int
	Next *ListNode
}

// @lc code=start
func reverseList(head *ListNode) *ListNode {
	// 遍历时，使用 next 指向下一个节点
	curr := head       // 当前指针
	var prev *ListNode // 当前的上一个节点，最开始是空
	// 临时指针
	var next *ListNode

	// curr 从前向后遍历
	for curr != nil {
		// 临时指针先保存下一个指针，避免断开链表找不到下一个
		next = curr.Next
		// 开始反转
		curr.Next = prev
		// 开始下一个节点
		prev = curr
		curr = next
	}
	return prev
}

// @lc code=end
