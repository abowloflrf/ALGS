#include <iostream>
#include <unordered_map>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode *next;
    ListNode *sibling;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
        this->sibling = nullptr;
    }
};

//使用map pair保存新旧节点对应关系，以空间换时间
ListNode *copyList(ListNode *targetList) {
    //为了得到新节点与旧节点的对应关系，使用一个map
    unordered_map<ListNode *, ListNode *> nodePairs;

    ListNode *item = targetList;
    ListNode *newList = new ListNode(item->val);
    ListNode *tempNode = newList;
    nodePairs.insert({item, tempNode});
    //复制常规链表
    while (item->next) {
        tempNode->next = new ListNode(item->next->val);
        nodePairs.insert({item->next, tempNode->next});
        tempNode = tempNode->next;
        item = item->next;
    }
    //回到头部再次遍历赋值sibling指针
    item = targetList;
    tempNode = newList;
    while (item != nullptr) {
        if (item->sibling) tempNode->sibling = nodePairs[item->sibling];
        item = item->next;
        tempNode = tempNode->next;
    }
    return newList;
}

int main() {
    ListNode *list = new ListNode(1);
    ListNode *node2 = list->next = new ListNode(2);
    ListNode *node3 = node2->next = new ListNode(3);
    ListNode *node4 = node3->next = new ListNode(4);
    ListNode *node5 = node4->next = new ListNode(5);

    list->sibling = node3;
    node2->sibling = node5;
    node4->sibling = node2;

    ListNode *listCopy = copyList(list);
    return 0;
}