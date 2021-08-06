/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (53.85%)
 * Likes:    620
 * Dislikes: 0
 * Total Accepted:    289.6K
 * Total Submissions: 537.8K
 * Testcase Example:  '[1,1,2]'
 *
 * Given the head of a sorted linked list, delete all duplicates such that each
 * element appears only once. Return the linked list sorted as well.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,1,2]
 * Output: [1,2]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,1,2,3,3]
 * Output: [1,2,3]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 300].
 * -100 <= Node.val <= 100
 * The list is guaranteed to be sorted in ascending order.
 *
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *curr = head;
        while (curr) {
            if (curr->next) {
                if (curr->val == curr->next->val) {
                    curr->next = curr->next->next;
                    // 这里注意，若下一个要删除跳过，则 curr 不能直接走向下一个，还要继续判断 next
                    continue;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
// @lc code=end
