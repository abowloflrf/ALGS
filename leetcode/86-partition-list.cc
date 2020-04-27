/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (38.77%)
 * Likes:    1081
 * Dislikes: 274
 * Total Accepted:    202.9K
 * Total Submissions: 503.5K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * Example:
 *
 *
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *smallListDummy = new ListNode(0);
        ListNode *largeListDummy = new ListNode(0);
        ListNode *ps = smallListDummy;
        ListNode *pl = largeListDummy;
        while (head != nullptr) {
            if (head->val < x) {
                ps->next = head;
                ps = ps->next;
            } else {
                pl->next = head;
                pl = pl->next;
            }
            head = head->next;
        }
        // 这一行比较关键，第一次提交漏掉了，需要手动结束后半部分的链表
        pl->next = nullptr;

        ps->next = largeListDummy->next;
        return smallListDummy->next;
    }
};
// @lc code=end

int main() {
    Solution s;
    ListNode *l = newList({1, 4, 3, 2, 5, 2});
    auto r = s.partition(l, 3);
    return 0;
}
