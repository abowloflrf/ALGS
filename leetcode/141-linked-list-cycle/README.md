# 141. 环形链表

判断链表是否有环

快慢指针，每次快指针比慢指针多走一步

1. 若无环形，则快指针必定先走到尽头指向空节点
2. 若有环形链表，则快指针必定会与慢指针相遇

```c++
class Solution {
  public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;
        // 快慢指针，每次快指针比慢指针多走一步
        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            // 无环的条件：fast 比 slow 先走到尽头（指向 null）
            if (!fast || !fast->next)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 有环的条件：slow == fast 跳出 while 循环
        return true;
    }
};
```
