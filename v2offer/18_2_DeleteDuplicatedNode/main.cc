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

void deleteDuplication(ListNode** list) {
    //传入的是空指针，空节点，单个节点
    if (list == nullptr || *list == nullptr || (*list)->next == nullptr) return;

    ListNode* prev = nullptr;
    ListNode* node = *list;
    while (node) {
        ListNode* next = node->next;

        if (next && node->val == next->val) {
            // delete
            int sameValue = node->val;
            ListNode* deleteNode = node;
            while (deleteNode && deleteNode->val == sameValue) {
                next = deleteNode->next;  //保存下一个节点
                delete deleteNode;        //删除
                deleteNode = next;        //移动到下一个节点
            }
            //若从第一位就开始删除
            if (prev == nullptr)
                *list = next;
            else
                prev->next = next;
            node = next;
        } else {
            // go on
            prev = node;
            node = node->next;
        }
    }
}

int main() {
    ListNode* list = new ListNode(11);
    list->next = new ListNode(12);
    list->next->next = new ListNode(13);                    // to be deleted
    list->next->next->next = new ListNode(13);              // to be deleted
    list->next->next->next->next = new ListNode(14);        // to be deleted
    list->next->next->next->next->next = new ListNode(14);  // to be deleted
    list->next->next->next->next->next->next = new ListNode(15);
    deleteDuplication(&list);
    return 0;
}
