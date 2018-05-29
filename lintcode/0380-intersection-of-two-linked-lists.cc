/**
 * 找到两个单链表最开始的交叉节点
 * A:        a1 → a2
 *                  ↘
 *                    c1 → c2 → c3
 *                  ↗
 * B:   b1 → b2 → b3
 */
#include <iostream>
class ListNode {
   public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

/**
 * 首先需要明确两个链表有交集则从交集开始后面均相同
 * 计算两条链表的长度分别为m和n，然后计算长度差
 * 根据长度差然，较长的链表先前进abs(m-n)长度，则两链表已经对齐
 * 对齐后交叉处之前两链表的长度也是相同的，因此再同时让两个链表前进直到相遇即可
 * 时间复杂度为O(n)，没有额外的空间消耗
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *t1 = headA, *t2 = headB;
    if (t1 == t2) return t1;
    if (t1 == NULL || t2 == NULL) return NULL;
    int lenA = 0, lenB = 0;
    int sub = 0;
    //计算长度差
    while (t1 || t2) {
        if (!t1 && t2) {
            sub++;
            t2 = t2->next;
            continue;
        }
        if (!t2 && t1) {
            sub--;
            t1 = t1->next;
            continue;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    // t2比t1长
    if (sub > 0) {
        while (sub != 0) {
            headB = headB->next;
            sub--;
        }
    }
    // t2比t1短
    if (sub < 0) {
        while (sub != 0) {
            headA = headA->next;
            sub++;
        }
    }
    //此时已经完成对齐
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int main(int argc, char const *argv[]) {
    ListNode *l1 = new ListNode(10);
    l1->next = new ListNode(12);
    l1->next->next = new ListNode(13);
    l1->next->next->next = new ListNode(16);
    ListNode *l2 = l1->next;
    ListNode *res;
    res = getIntersectionNode(l1, l2);
    return 0;
}
