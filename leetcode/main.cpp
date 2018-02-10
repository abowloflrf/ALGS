#include <iostream>
#include <string>
#include <vector>
#include "./src/002AddTwoNumbers.cpp"

int main()
{
    //Solution test = Solution();
    ListNode *nodeA, *nodeB;
    nodeA = new ListNode(2);
    nodeA->next = new ListNode(4);
    nodeA->next->next = new ListNode(3);

    nodeB = new ListNode(5);
    nodeB->next = new ListNode(6);
    nodeB->next->next = new ListNode(4);
    nodeB->next->next->next = new ListNode(5);

    Solution test = Solution();
    ListNode *nodeResult = test.addTwoNumbers(nodeA, nodeB);
    return 0;
}