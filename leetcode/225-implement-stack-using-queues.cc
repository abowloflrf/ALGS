/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 *
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (41.30%)
 * Likes:    494
 * Dislikes: 514
 * Total Accepted:    160.6K
 * Total Submissions: 374.9K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a stack using queues.
 *
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 *
 *
 * Example:
 *
 *
 * MyStack stack = new MyStack();
 *
 * stack.push(1);
 * stack.push(2);
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 *
 * Notes:
 *
 *
 * You must use only standard operations of a queue -- which means only push to
 * back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may
 * simulate a queue by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 *
 *
 */

#include <iostream>
#include <queue>

using namespace std;

// @lc code=start
class MyStack {
  public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        queueA.push(x);
        topEle = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (queueA.size() > 1) {
            topEle = queueA.front();
            queueA.pop();
            queueB.push(topEle);
        }
        int popEle = queueA.front();
        queueA.pop();

        //交换ab两个队列
        queue<int> tmp = queueA;
        queueA = queueB;
        queueB = tmp;
        return popEle;
    }

    /** Get the top element. */
    int top() { return topEle; }

    /** Returns whether the stack is empty. */
    bool empty() { return queueA.empty(); }

  private:
    queue<int> queueA;
    queue<int> queueB;
    int topEle;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);

    cout << stack.top() << endl;
    cout << stack.pop() << endl;
    cout << stack.empty() << endl;
    return 0;
}