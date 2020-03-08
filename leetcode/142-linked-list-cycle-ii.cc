/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (33.90%)
 * Likes:    2148
 * Dislikes: 176
 * Total Accepted:    280.1K
 * Total Submissions: 791.7K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 *
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects
 * to. If pos is -1, then there is no cycle in the linked list.
 *
 * Note: Do not modify the linked list.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 *
 *
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 *
 *
 *
 *
 *
 *
 * Follow-up:
 * Can you solve it without using extra space?
 *
 */
#include "utils/list.h"
#include <unordered_set>
using namespace std;
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        // 先使用快慢指针方式找到相遇点
        ListNode *slow = head;
        ListNode *fast = head;
        while (true) {
            // 若有环形链表则fast永远没有尽头，即其next指针永远不为空
            if (fast == nullptr || fast->next == nullptr)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        // 首节点和相遇点，两个点以相同的速度向前，其相遇点为环形的起点，作图可证明
        ListNode *node1 = head;
        ListNode *node2 = slow;
        while (node1 != node2) {
            node1 = node1->next;
            node2 = node2->next;
        }
        return node1;
    }
};
// @lc code=end
