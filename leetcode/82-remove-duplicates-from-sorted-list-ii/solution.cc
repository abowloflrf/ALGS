/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (52.77%)
 * Likes:    673
 * Dislikes: 0
 * Total Accepted:    160.9K
 * Total Submissions: 304.9K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given the head of a sorted linked list, delete all nodes that have duplicate
 * numbers, leaving only distinct numbers from the original list. Return the
 * linked list sorted as well.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,1,1,2,3]
 * Output: [2,3]
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
#include <vector>
using namespace std;
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
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = head;
        ListNode *slow = dummy;

        while (fast && fast->next) {
            if (fast->val == fast->next->val) {
                while (fast->next && fast->val == fast->next->val) {
                    fast = fast->next;
                }
                slow->next = fast->next;
                fast = fast->next;
                // 此时 slow 和 fast 可能相等？
                // 若最开始 slow 使用 dummy 节点则不会
            } else {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

ListNode *buildList(vector<int> input) {
    ListNode *dummy = new ListNode(0);
    ListNode *tmp = dummy;
    for (int i : input) {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    return dummy->next;
}

int main(int argc, char const *argv[]) {
    Solution s;
    auto ans = s.deleteDuplicates(buildList({1, 2, 3, 3, 4, 5}));
    return 0;
}
