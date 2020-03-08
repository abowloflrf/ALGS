#include "./utils/list.h"
#include <unordered_set>
#include <vector>

using namespace std;
// hash
class Solution {
  public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> records;
        while (head) {
            if (records.find(head) != records.end())
                return true;
            records.insert(head);
            head = head->next;
        }
        return false;
    }
};

// 快慢指针
class Solution2 {
  public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode *slow = head;
        ListNode *fast = head->next;

        // 每次fast比slow指针多前进一步，若有环形链表，则fast必定会追上slow
        while (slow != fast) {
            // 若有环形链表则fast永远没有尽头，即其next指针永远不为空
            if (fast == nullptr || fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};