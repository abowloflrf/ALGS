/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (48.84%)
 * Likes:    1066
 * Dislikes: 0
 * Total Accepted:    280.5K
 * Total Submissions: 574.4K
 * Testcase Example:  '[1,2,2,1]'
 *
 * Given the head of a singly linked list, return true if it is a
 * palindrome.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,2,1]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 10^5].
 * 0 <= Node.val <= 9
 *
 *
 *
 * Follow up: Could you do it in O(n) time and O(1) space?
 */

#include <stack>
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
    bool isPalindrome(ListNode *head) {
        ListNode *tmp = head;
        int size = 0;
        while (tmp) {
            size++;
            tmp = tmp->next;
        }

        stack<int> s;
        tmp = head;
        for (int i = 0; i < size / 2; i++) {
            s.push(tmp->val);
            tmp = tmp->next;
        }
        if (size % 2) {
            tmp = tmp->next;
        }
        while (tmp) {
            if (tmp->val != s.top()) {
                return false;
            } else {
                s.pop();
                tmp = tmp->next;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);

    bool b = s.isPalindrome(l);
    return 0;
}
