/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (38.29%)
 * Likes:    1743
 * Dislikes: 338
 * Total Accepted:    237.4K
 * Total Submissions: 597.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 *
 *
 *
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 */
#include "utils/list.h"
#include <stack>
#include <vector>
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        stack<ListNode *> s;
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while (true) {
            // 将k个节点入栈，head为这组节点中的头一个
            ListNode *tmp = head;
            while (tmp != nullptr && s.size() < k) {
                s.push(tmp);
                tmp = tmp->next;
            }
            // 循环结束后 tmp指向的是下一个组节点的头一个

            // 若栈中足k个节点，说明到了链表的最后一个组
            if (s.size() != k) {
                p->next = head;
                break;
            }
            // 依次出栈，完成这组节点的链表翻转
            while (!s.empty()) {
                p->next = s.top();
                s.pop();
                p = p->next;
            }

            p->next = tmp;
            head = tmp;
        }
        return dummy->next;
    }
};
// @lc code=end

// 不用额外的空间，正常翻转链表的方式
class Solution2 {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {}
    ListNode *reverseSubgroup(ListNode *head, int k) {
        ListNode *curr = head, *tail = head;
        ListNode *prev = nullptr, *tmp = nullptr;

        while (k--) {
            if (!curr)
                break;
            tmp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = tmp;
        }
        tail -> next = tmp;
        return prev;
    }
};

ListNode *newList(vector<int> data) {
    if (data.size() == 0)
        return nullptr;
    ListNode *l = new ListNode(data.front());
    ListNode *head = l;
    for (int i = 1; i < data.size(); i++) {
        l->next = new ListNode(data[i]);
        l = l->next;
    }
    return head;
}

int main() {
    Solution2 s;
    ListNode *list = newList({1, 2, 3, 4, 5, 6, 7, 8});
    
    ListNode *tmp = list, *head = list;
    tmp = s.reverseSubgroup(tmp, 3);
    tmp = s.reverseSubgroup(tmp->next, 3);
    tmp = s.reverseSubgroup(tmp->next, 3);

    return 0;
}
