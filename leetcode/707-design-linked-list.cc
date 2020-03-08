/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 *
 * https://leetcode.com/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (20.87%)
 * Likes:    441
 * Dislikes: 599
 * Total Accepted:    44.6K
 * Total Submissions: 200.6K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\r\n' +
  '[[],[1],[3],[1,2],[1],[1],[1]]\r'
 *
 * Design your implementation of the linked list. You can choose to use the
 * singly linked list or the doubly linked list. A node in a singly linked list
 * should have two attributes: val and next. val is the value of the current
 * node, and next is a pointer/reference to the next node. If you want to use
 * the doubly linked list, you will need one more attribute prev to indicate
 * the previous node in the linked list. Assume all nodes in the linked list
 * are 0-indexed.
 *
 * Implement these functions in your linked list class:
 *
 *
 * get(index) : Get the value of the index-th node in the linked list. If the
 * index is invalid, return -1.
 * addAtHead(val) : Add a node of value val before the first element of the
 * linked list. After the insertion, the new node will be the first node of the
 * linked list.
 * addAtTail(val) : Append a node of value val to the last element of the
 * linked list.
 * addAtIndex(index, val) : Add a node of value val before the index-th node in
 * the linked list. If index equals to the length of linked list, the node will
 * be appended to the end of linked list. If index is greater than the length,
 * the node will not be inserted.
 * deleteAtIndex(index) : Delete the index-th node in the linked list, if the
 * index is valid.
 *
 *
 *
 *
 * Example:
 *
 *
 * Input:
 *
 * ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
 * [[],[1],[3],[1,2],[1],[1],[1]]
 * Output:
 * [null,null,null,null,2,null,3]
 *
 * Explanation:
 * MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
 * linkedList.get(1);            // returns 2
 * linkedList.deleteAtIndex(1);  // now the linked list is 1->3
 * linkedList.get(1);            // returns 3
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= index,val <= 1000
 * Please do not use the built-in LinkedList library.
 * At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex
 * and deleteAtIndex.
 *
 *
 */
#include <iostream>
using namespace std;

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

// @lc code=start
// 定义链表节点数据结构
class MyLinkedList {
  private:
    int size;
    ListNode *head;
    ListNode *tail;

  public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size)
            return -1;
        ListNode *tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        return tmp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be
     * the first node of the linked list. */
    void addAtHead(int val) { this->addAtIndex(0, val); }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) { this->addAtIndex(size, val); }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked
     * list, the node will be appended to the end of linked list. If index is greater than the length, the node will not
     * be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;
        ListNode *node = new ListNode(val);
        // index=0时添加头节点
        if (index == 0) {
            node->next = head;
            head = node;
            if (size == 0)
                tail = head;
            size++;
            return;
        }
        // 其他情况
        ListNode *tmp = head;
        for (int i = 0; i < index - 1; i++)
            tmp = tmp->next;
        node->next = tmp->next;
        tmp->next = node;
        if (index == size)
            tail = node;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        // index==0时 删除头节点
        if (index == 0) {
            head = head->next;
            // size为1时，head tail 都指向null
            if (size == 1)
                tail = head;
            size--;
            return;
        }
        // 其他情况
        ListNode *tmp = head;
        for (int i = 0; i < index - 1; i++)
            tmp = tmp->next;
        delete tmp->next;
        tmp->next = tmp->next->next;
        if (size - 1 == index)
            tail = tmp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

int main(int argc, char const *argv[]) {

    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(2);
    obj->addAtTail(3);
    obj->addAtTail(4);
    obj->addAtTail(5);
    obj->addAtTail(6);
    obj->deleteAtIndex(5);
    obj->addAtHead(21);
    obj->addAtHead(22);

    return 0;
}
