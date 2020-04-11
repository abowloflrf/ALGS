/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (46.84%)
 * Likes:    1903
 * Dislikes: 158
 * Total Accepted:    430.7K
 * Total Submissions: 881.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *curr = head, *prev = new ListNode(0), *tmp = nullptr, *dummy = prev;
        while (curr != nullptr && curr->next != nullptr) {
            tmp = curr->next;
            prev->next = tmp;
            curr->next = curr->next->next;
            tmp->next = curr;
            // 下一组
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};
// @lc code=end
