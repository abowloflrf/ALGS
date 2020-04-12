/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (36.35%)
 * Likes:    1935
 * Dislikes: 126
 * Total Accepted:    250.8K
 * Total Submissions: 666.1K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n)
            return head;
        // 先找到第m个节点以及它前面一个节点
        ListNode *p = nullptr;
        ListNode *curr = head;
        for (int i = 1; i < m; i++) {
            p = curr;
            curr = curr->next;
        }

        // 翻转
        ListNode *tmp = nullptr, *prev = nullptr, *start = curr;
        for (int i = m; i <= n; i++) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // 连接
        if (p != nullptr)
            p->next = prev;
        else
            head = prev;
        start->next = curr;

        return head;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    ListNode *l = newList({1, 2});
    Solution s;
    ListNode *r = s.reverseBetween(l, 1, 2);
    return 0;
}
