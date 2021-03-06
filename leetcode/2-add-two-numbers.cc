/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.05%)
 * Likes:    7481
 * Dislikes: 1938
 * Total Accepted:    1.3M
 * Total Submissions: 3.9M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 *
 */
#include "utils/list.h"

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        int flag = 0; // 保存上次的进位
        while (l1 != nullptr || l2 != nullptr) {
            int n = 0;
            if (l1 == nullptr) {
                n = l2->val + flag;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                n = l1->val + flag;
                l1 = l1->next;
            } else {
                n = l1->val + l2->val + flag;
                l1 = l1->next;
                l2 = l2->next;
            }

            flag = 0;
            if (n >= 10) {
                flag = 1;
                n = n % 10;
            }
            p->next = new ListNode(n);
            p = p->next;
        }
        if (flag == 1)
            p->next = new ListNode(1);
        return dummy->next;
    }
};
// @lc code=end
