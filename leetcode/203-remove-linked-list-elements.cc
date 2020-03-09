/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (36.59%)
 * Likes:    1226
 * Dislikes: 72
 * Total Accepted:    287.6K
 * Total Submissions: 774.3K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example:
 *
 *
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *prev = dummy;
        while (prev->next) {
            if (prev->next->val == val)
                prev->next = prev->next->next;
            else
                prev = prev->next;
        }
        return dummy->next;
    }
};
// @lc code=end
