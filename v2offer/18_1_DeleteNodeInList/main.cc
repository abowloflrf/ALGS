#include <iostream>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// O(n) 解法，直接更改指针指向
void deleteNode1(ListNode** pList, ListNode* pTarget) {
    //目标是头节点
    if (pTarget == *pList) {
        *pList = pTarget->next;
        delete pTarget;
        return;
    }
    //找到目标节点
    ListNode* item = *pList;
    while (item->next) {
        // find node before target
        if (item->next == pTarget) break;
        item = item->next;
    }
    item->next = pTarget->next;
    delete pTarget;
    pTarget = nullptr;
}
// O(1) 解法，改变节点内容
void deleteNode2(ListNode** pList, ListNode* pTarget) {
    //要删除的是尾节点
    if (!pTarget->next) {
        //若只有一个节点，则直接删除该节点
        if (*pList == pTarget) {
            *pList = nullptr;
            delete pTarget;
            pTarget = nullptr;
        } else {
            //否则还需要遍历，找到目标的前一个节点将其next赋值为nullptr
            ListNode* item = *pList;
            // find node before target
            while (item->next != pTarget) {
                item = item->next;
            }
            item->next = nullptr;
        }
        return;
    }
    //目标节点在链表中，改变赋值
    ListNode* nextNode = pTarget->next;
    pTarget->val = nextNode->val;
    pTarget->next = nextNode->next;
    delete nextNode;
    nextNode = nullptr;
}

int main() {
    ListNode* list = new ListNode(11);
    ListNode* node12 = list->next = new ListNode(12);
    ListNode* node13 = list->next->next = new ListNode(13);
    ListNode* node14 = list->next->next->next = new ListNode(14);
    deleteNode1(&list, list);
    return 0;
}