//
// Created by ruofeng on 2018/7/30.
//
// 移除链表的倒数第n个节点
class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *nodeFront = head;
        ListNode *nodeBack = head;
        //先让nodeFront前进n个位置，即比nodeBack领先n个位置
        for (int i = 0; i < n; i++)
            nodeFront = nodeFront->next;
        if (nodeFront == nullptr)
            return nodeBack->next;
        while (nodeFront->next != nullptr) {
            nodeFront = nodeFront->next;
            nodeBack = nodeBack->next;
        }
        nodeBack->next = nodeBack->next->next;
        return head;
    }
};

int main() {
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode *l = s.removeNthFromEnd(list, 5);
    return 0;
}