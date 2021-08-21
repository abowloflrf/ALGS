/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] Insertion Sort List
 *
 * https://leetcode-cn.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (68.02%)
 * Likes:    420
 * Dislikes: 0
 * Total Accepted:    96.3K
 * Total Submissions: 141.5K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a singly linked list, sort the list using insertion sort,
 * and return the sorted list's head.
 *
 * The steps of the insertion sort algorithm:
 *
 *
 * Insertion sort iterates, consuming one input element each repetition and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list and inserts it
 * there.
 * It repeats until no input elements remain.
 *
 *
 * The following is a graphical example of the insertion sort algorithm. The
 * partially sorted list (black) initially contains only the first element in
 * the list. One element (red) is removed from the input data and inserted
 * in-place into the sorted list with each iteration.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 5000].
 * -5000 <= Node.val <= 5000
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 断开 head 和后面的部分
        ListNode *newhead = head;
        ListNode *curr = head->next;
        head->next = nullptr;

        while (curr) {
            // 先临时保存 curr 的下一个
            ListNode *nextcurr = curr->next;

            // 从头节点开始判断当前节点应该插入到哪里，遍历链表找到最后一个小于 curr 的节点，插入到它的后面
            ListNode *target = nullptr;
            ListNode *node = newhead;
            while (node) {
                if (node->val < curr->val) {
                    target = node;
                }
                node = node->next;
            }
            if (!target) {
                // 所有数都比它大，应放在最前面
                curr->next = newhead;
                newhead = curr;
            } else {
                // 找到最后一个比它小的节点，插入到它后面
                ListNode *targetNext = target->next;
                target->next = curr;
                curr->next = targetNext;
            }
            // 判断下一个
            curr = nextcurr;
        }
        return newhead;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    ListNode *node = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    Solution s;
    auto ans = s.insertionSortList(node);
    return 0;
}
