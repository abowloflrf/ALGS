#include <iostream>
//链表结构
class ListNode {
   public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1);  // 头节点
    int carry = 0;
    ListNode *prev = &dummy;

    ListNode *pa = l1;
    ListNode *pb = l2;
    //开始对两个链表同时遍历循环，若两个链表都到头了则停止
    while (pa != nullptr || pb != nullptr) {
        //这里判断链表中的单个数据，若链表到头了即指向的为空指针则返回一个0，若没有到头则返回节点中的数据
        const int ai = pa == nullptr ? 0 : pa->val;
        const int bi = pb == nullptr ? 0 : pb->val;
        //这里判断是同一位，可以相加，但是要留一个进位
        const int value = (ai + bi + carry) % 10;
        carry = (ai + bi + carry) >= 10 ? 1 : 0;
        prev->next = new ListNode(value);  // 从尾部开始插入节点
        //若有一条链表到头则直接返回空指针，若没有到头则指向下一个节点
        pa = pa == nullptr ? nullptr : pa->next;
        pb = pb == nullptr ? nullptr : pb->next;
        prev = prev->next;
    }
    //若最后一次判断仍有进位则再加一位
    if (carry > 0) prev->next = new ListNode(carry);
    //除去头节点从有效数据开始返回结果链表
    return dummy.next;
}