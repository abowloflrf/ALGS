//
// Created by ruofeng on 2018/7/24.
//

#include <iostream>

using namespace std;

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode *getCommon(ListNode *list1, ListNode *list2) {
    int length1 = 0, length2 = 0;
    ListNode *node = list1;
    while (node) {
        length1++;
        node = node->next;
    }
    node = list2;
    while (node) {
        length2++;
        node = node->next;
    }
    int distance = length1 - length2;
    //1长于2，则将1先走distance位
    if (distance >= 0) {
        for (int i = 0; i < distance; i++) {
            list1 = list1->next;
        }
    } else {
        for (int i = 0; i < -distance; i++) {
            list2 = list2->next;
        }
    }
    while (list1 != nullptr && list2 != nullptr) {
        if (list1 == list2)
            return list1;
        list1 = list1->next;
        list2 = list2->next;
    }
    return nullptr;
}

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = node1->next = new ListNode(2);
    ListNode *node3 = node2->next = new ListNode(3);
    ListNode *node4 = node3->next = new ListNode(4);
    ListNode *node5 = node4->next = new ListNode(5);
    ListNode *node6 = node5->next = new ListNode(6);

    ListNode *node100 = new ListNode(100);
    ListNode *node101 = node100->next = new ListNode(101);
    ListNode *node102 = node101->next = new ListNode(102);
    node102->next = node3;
    ListNode *commonNode = getCommon(node1, node100);
    cout << commonNode->val << endl;
    return 0;
}
