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
     * @param head: the first Node
     * @tips: 确定从最低位开始第一个不为9的节点位置，然后此位加一，后面全部为0
     * @return: the answer after plus one
     */
    ListNode *plusOne(ListNode *head) {
        // Write your code here
        ListNode *lastNot9Node = nullptr;
        ListNode *tmpNode = head;

        while (tmpNode) {
            if (tmpNode->val != 9) lastNot9Node = tmpNode;
            tmpNode = tmpNode->next;
        }

        if (lastNot9Node == nullptr) {
            ListNode *newNodeHead = new ListNode(1);
            newNodeHead->next = head;
            while (head) {
                head->val = 0;
                head = head->next;
            }
            return newNodeHead;
        }

        tmpNode = lastNot9Node->next;
        lastNot9Node->val++;
        while (tmpNode) {
            tmpNode->val = 0;
            tmpNode = tmpNode->next;
        }
        return head;
    }
};