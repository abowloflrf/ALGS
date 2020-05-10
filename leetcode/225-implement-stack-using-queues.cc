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
  private:
    queue<int> q1;
    queue<int> q2;
    int topEle;

  public:
    /** Initialize your data structure here. */
    MyStack() {
        q1 = {};
        q2 = {};
        topEle = -1;
    }

    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        topEle = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // 把q1全部pop到q2，q1只剩最后一个就是要pop的目标
        // 同时最后一个从q1 pop出来的数为下一个topEle
        while (q1.size() > 1) {
            topEle = q1.front();
            q1.pop();
            q2.push(topEle);
        }
        // 记录q1剩下的最后一个，然后pop掉
        int target = q1.front();
        q1.pop();
        // q2 换回到 q1
        q1 = q2;
        q2 = {};
        return target;
    }

    /** Get the top element. */
    int top() {
        if (q1.empty())
            return -1;
        return topEle;
    }

    /** Returns whether the stack is empty. */
    bool empty() { return q1.empty(); }
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