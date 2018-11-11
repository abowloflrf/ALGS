#include <iostream>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
   public:
    /**
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return head;

        ListNode *h = head;
        ListNode *next = head->next;
        ListNode *tmpNode = head->next;
        head->next = NULL;  //先断开头节点
        while (next) {
            tmpNode = next->next;  //保存下一个节点
            next->next = head;  //将第二的节点接在断开的头节点前面
            head = next;  //新链表的头节点指向刚刚接在前面的节点
            next = tmpNode;  //继续指向下一个节点
        }
        return head;
    }
};

int main(int argc, char const *argv[]) {
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    Solution s;
    s.reverse(list);
    return 0;
}