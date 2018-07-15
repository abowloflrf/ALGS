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

ListNode* getKthFromLast(ListNode* list, int k) {
    if (k < 1) return nullptr;
    
    ListNode* nodeA = list;

    //先让A向前走k步
    for (int i = 0; i < k; i++) {
        nodeA = nodeA->next;
        if (nodeA == nullptr) return nullptr;
    }
    ListNode* nodeB = list;

    // AB同时向前，直到节点A到末尾
    while (nodeA) {
        nodeA = nodeA->next;
        nodeB = nodeB->next;
    }
    return nodeB;
}

int main() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next = new ListNode(6);

    ListNode* nodeK = getKthFromLast(list, 10);  // 4
    if (nodeK)
        cout << nodeK->val << endl;
    else
        cout << "input k error" << endl;
    return 0;
}