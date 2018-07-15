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

ListNode* reverseList(ListNode* list) {
    //空链表或只有一个节点的链表
    if (list == nullptr || list->next == nullptr) return list;

    ListNode* head = list;
    ListNode* next = list->next;
    ListNode* temp = list->next;
    list->next = nullptr;
    while (next) {
        temp = next->next;
        next->next = head;
        head = next;
        next = temp;
    }
    return head;
}

int main() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    list->next->next->next->next->next = new ListNode(6);

    ListNode* reversedList = reverseList(list);

    // print list
    while (reversedList->next) {
        cout << reversedList->val << "->";
        reversedList = reversedList->next;
    }
    cout << reversedList->val<<endl;

    return 0;
}