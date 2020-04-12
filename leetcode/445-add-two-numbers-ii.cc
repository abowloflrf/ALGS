/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (51.65%)
 * Likes:    1173
 * Dislikes: 140
 * Total Accepted:    138.4K
 * Total Submissions: 260.3K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 *
 *
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 *
 *
 */
#include "utils/list.h"
#include <stack>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<ListNode *> s1;
        stack<ListNode *> s2;
        while (l1) {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *p = nullptr;
        int sumn = 0;
        while (!s1.empty() || !s2.empty()) {
            if (s1.empty()) {
                sumn = s2.top()->val + carry;
                s2.pop();
            } else if (s2.empty()) {
                sumn = s1.top()->val + carry;
                s1.pop();
            } else {
                sumn = s1.top()->val + s2.top()->val + carry;
                s1.pop();
                s2.pop();
            }
            carry = 0;
            if (sumn > 9) {
                carry = 1;
                sumn = sumn % 10;
            }
            // 注意1: 这里需要倒着构造结果链表
            ListNode *newNode = new ListNode(sumn);
            newNode->next = p;
            p = newNode;
        }
        // 注意2: 最后还要判断最高一位有没有carry
        if (carry) {
            ListNode *newNode = new ListNode(1);
            newNode->next = p;
            p = newNode;
        }
        return p;
    }
};
// @lc code=end
