//
// Created by ruofeng on 5/28/18.
//
#include "./utils/list.h"
#include <iostream>

using namespace std;

// 先新建一个链表，然后在l1 l2中分别判断哪个小，并加入到新的链表中
class Solution1 {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // 新建一个链表，有一个节点值为-1
        // 仅仅为方便操作，返回时忽略掉这个节点，返回 list->next
        ListNode *newList = new ListNode(-1);
        ListNode *cur = newList;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        // 最后可能还剩下一个l1或者l2
        if (l1)
            cur->next = l1;
        else
            cur->next = l2;
        return newList->next;
    }
};

// 递归方式
class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        //递归求解
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};
