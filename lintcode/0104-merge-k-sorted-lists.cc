#include <iostream>
#include <vector>
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }

   private:
    ListNode *merge(vector<ListNode *> &lists, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            ListNode *l1 = merge(lists, start, mid);
            ListNode *l2 = merge(lists, mid + 1, end);
            return mergeTwoLists(l1, l2);
        }
        return lists[start];
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        //递归求解
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};

int main(int argc, char const *argv[]) {
    ListNode *l1 = new ListNode(3);
    l1->next = new ListNode(5);
    l1->next->next = new ListNode(9);

    ListNode *l2 = new ListNode(7);
    l2->next = new ListNode(8);
    l2->next->next = new ListNode(9);

    ListNode *l3 = new ListNode(1);
    l3->next = new ListNode(20);
    l3->next->next = new ListNode(21);

    Solution *s = new Solution();
    vector<ListNode *> vec = {l1, l2, l3};
    ListNode *res = s->mergeKLists(vec);

    return 0;
}
