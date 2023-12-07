/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.cn/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (64.64%)
 * Likes:    755
 * Dislikes: 0
 * Total Accepted:    225.8K
 * Total Submissions: 349.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered
 * list.
 *
 * The first node is considered odd, and the second node is even, and so on.
 *
 * Note that the relative order inside both the even and odd groups should
 * remain as it was in the input.
 *
 * You must solve the problem in O(1) extra space complexity and O(n) time
 * complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [2,1,3,5,6,4,7]
 * Output: [2,3,6,7,1,5,4]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the linked list is in the range [0, 10^4].
 * -10^6 <= Node.val <= 10^6
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
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        // evenList 用来存偶数位的新节点
        ListNode *evenList = new ListNode(0);
        ListNode *evenHead = evenList;
        ListNode *p = head;
        while (p->next != nullptr) {
            // 把偶节点放到 evenList 末尾
            evenList->next = p->next;
            evenList = evenList->next;
            // 删除这个偶节点
            p->next = p->next->next;
            if (p->next == nullptr) {
                break;
            }
            p = p->next;
        }
        // 断掉 evenList 末尾
        evenList->next = nullptr;
        // 连接两个链表
        p->next = evenHead->next;
        return head;
    }
};
// @lc code=end
