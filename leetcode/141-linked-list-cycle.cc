#include <unordered_set>
#include <vector>

using namespace std;

class ListNode {
   public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        unordered_set<ListNode *> records;
        ListNode *node = head;
        while (node->next) {
            if (records.find(node) != records.end()) return true;
            records.insert(node);
            node = node->next;
        }
        return false;
    }
};