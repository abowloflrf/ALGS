/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.76%)
 * Likes:    1262
 * Dislikes: 0
 * Total Accepted:    197.9K
 * Total Submissions: 296.4K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a linked list, return the list after sorting it in
 * ascending order.
 *
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
 * (i.e. constant space)?
 *
 *
 * Example 1:
 *
 *
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
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
 * The number of nodes in the list is in the range [0, 5 * 10^4].
 * -10^5 <= Node.val <= 10^5
 *
 *
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 1. 快慢指针找到中间节点
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. 从中间断开节点为左右两个部分
        ListNode *tmp = slow->next;
        slow->next = nullptr;

        // 3. 左右两个链表分别递归调用 sortList
        ListNode *left = sortList(head);
        ListNode *right = sortList(tmp);

        // 4. 合并左右两个排序链表
        ListNode *dummy = new ListNode(0);
        ListNode *node = dummy;
        while (left && right) {
            if (left->val < right->val) {
                node->next = left;
                left = left->next;
            } else {
                node->next = right;
                right = right->next;
            }
            node = node->next;
        }
        while (left) {
            node->next = left;
            left = left->next;
            node = node->next;
        }
        while (right) {
            node->next = right;
            right = right->next;
            node = node->next;
        }
        return dummy->next;
    }
};
// @lc code=end
