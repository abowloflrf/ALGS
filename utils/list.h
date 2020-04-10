//
// Created by Ruofeng Lei on 2019/10/18.
//

#ifndef ALGS_LIST_H
#define ALGS_LIST_H

#include <vector>
// ListNode 单向链表节点
class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

// newList 创建一条链表
ListNode *newList(std::vector<int> data) {
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
#endif // ALGS_LIST_H
