/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (34.40%)
 * Likes:    1374
 * Dislikes: 100
 * Total Accepted:    232.1K
 * Total Submissions: 650.2K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * Return the linked list sorted as well.
 *
 * Example 1:
 *
 *
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 *
 *
 * Example 2:
 *
 *
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = dummy->next, *slow = dummy;
        while (fast != nullptr && fast->next != nullptr) {
            if (fast->val == fast->next->val) {
                while (fast->next != nullptr && fast->val == fast->next->val) {
                    fast = fast->next;
                }
                slow->next = fast->next;
                fast = slow->next;
            } else {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

int main() {
    auto list = newList({1, 2, 3, 3, 4, 4, 5});
    Solution s;
    auto newL = s.deleteDuplicates(list);
    return 0;
}