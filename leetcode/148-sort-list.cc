/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (39.59%)
 * Likes:    2172
 * Dislikes: 110
 * Total Accepted:    234.7K
 * Total Submissions: 592.8K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * Example 1:
 *
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 *
 *
 * Example 2:
 *
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 *
 */

#include "./utils/list.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        // 使用快慢指针的方式找到链表中间的节点
        ListNode *fast = head->next, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 从中间断开两个链表，左右部分分别为head tmp
        ListNode *tmp = slow->next;
        slow->next = nullptr;

        // 对左右两部分分别再执行sortList
        ListNode *left = sortList(head);
        ListNode *right = sortList(tmp);

        // 对两个已排序的链表进行合并 参考 leetcode-21
        ListNode *newList = new ListNode(-1);
        ListNode *newTmp = newList;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                newList->next = left;
                left = left->next;
            } else {
                newList->next = right;
                right = right->next;
            }
            newList = newList->next;
        }
        if (left)
            newList->next = left;
        else
            newList->next = right;
        return newTmp->next;
    }
};
// @lc code=end
