//
// Created by Ruofeng Lei on 2019/10/18.
//

#ifndef ALGS_LIST_H
#define ALGS_LIST_H

// ListNode 单向链表节点
class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

#endif // ALGS_LIST_H
