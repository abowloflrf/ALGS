/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (28.19%)
 * Likes:    993
 * Dislikes: 967
 * Total Accepted:    251.5K
 * Total Submissions: 861.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 *
 * Example 1:
 *
 *
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 *
 * k=4
 * 2->3->4->5->1->NULL
 *
 * Example 2:
 *
 *
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr)
            return head;
        ListNode *p = head;
        int listSize = 1;
        // 先找到尾节点
        while (p->next != nullptr) {
            p = p->next;
            listSize++;
        }
        ListNode *endNode = p;
        // k%=listSize 避免k太大做了过多遍无意义的遍历
        k %= listSize;
        // k==size 直接返回首节点，没有变换
        if (k == 0)
            return head;

        // 找到要断开的位置
        p = head;
        for (int i = 0; i < listSize - k - 1; i++) {
            p = p->next;
        }
        ListNode *newHead = p->next;
        p->next = nullptr;
        endNode->next = head;
        return newHead;
    }
};
// @lc code=end
