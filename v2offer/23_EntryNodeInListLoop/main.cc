#include <iostream>
#include <unordered_set>

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

ListNode* getEntry(ListNode* list) {
    unordered_set<ListNode*> visitedNodes;
    ListNode* item = list;
    while (item) {
        //若找到
        if (visitedNodes.find(item) != visitedNodes.end()) return item;
        visitedNodes.insert(item);
        item = item->next;
    }
    return nullptr;
}

int main() {
    ListNode* list = new ListNode(1);
    ListNode* node1 = list;
    ListNode* node2 = node1->next = new ListNode(2);
    ListNode* node3 = node2->next = new ListNode(3);
    ListNode* node4 = node3->next = new ListNode(4);
    ListNode* node5 = node4->next = new ListNode(5);
    ListNode* node6 = node5->next = new ListNode(6);
    node6->next = node3;
    //假设一定会有环
    ListNode* entry = getEntry(list);
    cout << entry->val << endl;
    return 0;
}