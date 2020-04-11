/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (32.82%)
 * Likes:    1518
 * Dislikes: 100
 * Total Accepted:    208.4K
 * Total Submissions: 594.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 * Example 1:
 *
 *
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 *
 * Example 2:
 *
 *
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 *
 *
 */
#include "utils/list.h"
// @lc code=start
/**
 * 1->2->3->4->5->6  => 1->6->2->5->3->4
 * 1->2->3->4->5 => 1->5->2->4->3
 *
 * 例如 1->2->3->4->5->6
 * 1. 找到中间节点3，将原链表分成前后两个链表lista(1->2->3) listb(4->5->6)
 * 2. listb翻转 (6->5->4)
 * 3. 将listb(6->5->4)中的元素依次间隔插入到lista中(1->2->3)
 * 4. 得到1->6->2->5->3->4
 **/
class Solution {
  public:
    void reorderList(ListNode *head) {
        if (head == nullptr)
            return;
        // 快慢指针找到中间节点
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 从中间断开，分成左右两个链表
        ListNode *left = head;
        ListNode *right = slow->next;
        slow->next = nullptr;
        // 翻转右链表
        ListNode *curr = right, *prev = nullptr, *tmp = nullptr;
        while (curr) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        right = prev;
        // 将右链表的节点依次间隔插入到左链表
        ListNode *lp = left, *rp = right, *tmpRight = right;
        while (rp != nullptr) {
            tmpRight = rp;
            rp = rp->next;

            tmp = lp->next;
            tmpRight->next = tmp;
            lp->next = tmpRight;
            lp = tmp;
        }
    }
};
// @lc code=end
int main() {
    ListNode *head = newList({1, 2, 3, 4});
    Solution s;
    s.reorderList(head);
    return 0;
}