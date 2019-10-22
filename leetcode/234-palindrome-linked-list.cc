/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (37.23%)
 * Likes:    2036
 * Dislikes: 291
 * Total Accepted:    310.8K
 * Total Submissions: 834.6K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Example 1:
 *
 *
 * Input: 1->2
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: 1->2->2->1
 * Output: true
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 *
 */

#include "utils/list.h"
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    // 判断是否是回文单向链表
    bool isPalindrome(ListNode *head) {
        // 不额外使用空间
        // 使用快慢指针获取链表的中点
        // 翻转一半的链表，然后与链表后半部分逐一比较

        ListNode *fast = head;
        ListNode *slow = head;
        while (fast) {
            // slow指针每次向前走一步
            slow = slow->next;
            // fast指针每次向前走两步
            fast = fast->next ? fast->next->next : nullptr;
            // 若长度为奇数 1.2.3.4.5
            // 最终：slow->4 fast->null
            // 若长度为偶数 1.2.3.4
            // 最终：slow->3 fast->null
        }
        // 翻转包括slow开始的后半部分
        ListNode *prev = nullptr, *tmp = nullptr;
        while (slow) {
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        // 比较两部分链表
        while (prev && head) {
            if (prev->val != head->val)
                return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};
// @lc code=end

// 此解 Time: O(n)， Space O(n), 用到了额外的vector结构去储存数据
class Solution_2 {
  public:
    // 判断是否是回文单向链表
    bool isPalindrome(ListNode *head) {
        int len = 0;
        vector<int> vec;
        while (head != nullptr) {
            vec.push_back(head->val);
            len++;
            head = head->next;
        }
        for (int i = 0; i < len; i++) {
            if (vec[i] != vec[len - 1 - i])
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    ListNode *l = nullptr;
    vector<int> vec{1, 2, 3, 4, 5, 4, 3, 2, 1};
    for (int i = 0; i < vec.size(); i++) {
        ListNode *tmp = new ListNode(vec[i]);
        if (l == nullptr)
            l = tmp;
        else {
            ListNode *ptr = l;
            while (ptr->next)
                ptr = ptr->next;
            ptr->next = tmp;
        }
    }
    Solution s;
    bool i = s.isPalindrome(l);
    return 0;
}
