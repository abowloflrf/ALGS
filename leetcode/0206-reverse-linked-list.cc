//
// Created by Ruofeng Lei on 2019/10/18.
// LeetCode Link: https://leetcode.com/problems/reverse-linked-list/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "list.h"

using namespace std;

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *current = head;
        ListNode *prev = nullptr, *tmp = nullptr;

        while (current) {
            // tmp保存下一个节点避免找不到了，因为一会儿next需要断开然后指向刚刚的head
            tmp = current->next;
            // 将当前遍历到的current节点指向上一个节点
            current->next = prev;

            // 保存current节点作为下一次循环的上一个节点
            prev = current;
            // 当前节点指向下一个
            current = tmp;
        }
        // 此时已经遍历已经结束，current指向了原链表的末尾null，prev变成了新链表的首节点
        return prev;
    }
};

TEST_CASE("0206-reverse-linked-list", "[leetcode]") {
    Solution s;
    auto *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);

}
