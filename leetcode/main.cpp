#include <vector>
#include "src/021MergeTwoSortedLists.cc"
using namespace std;
int main() {
    Solution s = Solution();
    ListNode *list1;
    list1 = (ListNode *)malloc(sizeof(ListNode));
    list1->val = 9;
    list1->next = (ListNode *)malloc(sizeof(ListNode));
    list1->next->val = 20;
    list1->next->next = (ListNode *)malloc(sizeof(ListNode));
    list1->next->next->val = 33;

    ListNode *list2;
    list2 = (ListNode *)malloc(sizeof(ListNode));
    list2->val = 1;
    list2->next = (ListNode *)malloc(sizeof(ListNode));
    list2->next->val = 3;
    list2->next->next = (ListNode *)malloc(sizeof(ListNode));
    list2->next->next->val = 4;

    ListNode *resultList;
    resultList = s.mergeTwoLists(list1, list2);

    return 0;
}