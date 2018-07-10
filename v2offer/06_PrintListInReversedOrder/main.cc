#include <iostream>
#include <stack>

using namespace std;
class ListNode {
   public:
    int data;
    ListNode *next;
    ListNode(int val) {
        this->data = val;
        this->next = NULL;
    }
};

void printList(ListNode *list) {
    stack<ListNode *> printStack;
    while (list->next) {
        printStack.push(list);
        list = list->next;
    }
    printStack.push(list);

    while (!printStack.empty()) {
        ListNode *node = printStack.top();
        printStack.pop();
        cout << node->data << endl;
    }
}

int main() {
    ListNode *list = new ListNode(10);
    list->next = new ListNode(9);
    list->next->next = new ListNode(8);
    list->next->next->next = new ListNode(7);
    printList(list);
    return 0;
}