#include <unordered_map>
using namespace std;

class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// 1. map 记录映射方法，需要额外的空间
class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return nullptr;
        unordered_map<Node *, Node *> M;
        Node *dummy = new Node(0);
        Node *newHead = dummy;
        Node *oldHead = head;
        while (oldHead) {
            newHead->next = new Node(oldHead->val);
            M[oldHead] = newHead->next;

            newHead = newHead->next;
            oldHead = oldHead->next;
        }
        for (Node *tmp = dummy->next, *old = head; tmp && old; tmp = tmp->next, old = old->next) {
            tmp->random = M[old->random];
        }
        return dummy->next;
    }
};

// 2. 构造拼接链表 原节点 1 -> 新节点 1 -> 原节点 2 -> 新节点 2 -> ……
// old->next->random = old->random->next
// 注意还需要恢复原链表，否则报错，Next pointer of node with label 7 from the original list was modified.
class Solution2 {
  public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return nullptr;
        Node *newList = head;

        // 构造拼接链表
        while (newList) {
            Node *tmp = new Node(newList->val);
            tmp->next = newList->next;
            newList->next = tmp;
            newList = tmp->next;
        }
        // 构造 random 指针
        newList = head;
        while (newList) {
            // 旧节点有 random 时才构造，否则会空指针错误
            if (newList->random) {
                newList->next->random = newList->random->next;
            }
            newList = newList->next->next;
        }

        // 构造新链表
        Node *newListDummy = new Node(0);
        Node *newListHead = newListDummy;
        newList = head;
        while (newList) {
            newListHead->next = newList->next;
            newListHead = newListHead->next;

            // 注意需要恢复原链表
            newList->next = newList->next->next;
            newList = newList->next;
        }
        return newListDummy->next;
    }
};

int main(int argc, char const *argv[]) {
    Solution2 s;
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    head->next->random = head;                               // 13->0
    head->next->next->random = head->next->next->next->next; // 11->4
    head->next->next->next->random = head->next;             // 10->2
    head->next->next->next->next->random = head;             // 1->0
    auto n = s.copyRandomList(head);
    return 0;
}
