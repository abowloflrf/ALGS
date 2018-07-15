#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    //递归求解
    if (l1->val < l2->val) {
        // l1的首位小于l2的首位
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        // l1的首位不小于l2的首位
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
}