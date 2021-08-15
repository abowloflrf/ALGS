/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 *
 * https://leetcode-cn.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (67.52%)
 * Likes:    359
 * Dislikes: 0
 * Total Accepted:    125.7K
 * Total Submissions: 186.2K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement a last-in-first-out (LIFO) stack using only two queues. The
 * implemented stack should support all the functions of a normal stack (push,
 * top, pop, and empty).
 *
 * Implement the MyStack class:
 *
 *
 * void push(int x) Pushes element x to the top of the stack.
 * int pop() Removes the element on the top of the stack and returns it.
 * int top() Returns the element on the top of the stack.
 * boolean empty() Returns true if the stack is empty, false otherwise.
 *
 *
 * Notes:
 *
 *
 * You must use only standard operations of a queue, which means that only push
 * to back, peek/pop from front, size and is empty operations are valid.
 * Depending on your language, the queue may not be supported natively. You may
 * simulate a queue using a list or deque (double-ended queue) as long as you
 * use only a queue's standard operations.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MyStack", "push", "push", "top", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * Output
 * [null, null, null, 2, 2, false]
 *
 * Explanation
 * MyStack myStack = new MyStack();
 * myStack.push(1);
 * myStack.push(2);
 * myStack.top(); // return 2
 * myStack.pop(); // return 2
 * myStack.empty(); // return False
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= x <= 9
 * At most 100 calls will be made to push, pop, top, and empty.
 * All the calls to pop and top are valid.
 *
 *
 *
 * Follow-up: Can you implement the stack using only one queue?
 *
 */
#include <queue>
using namespace std;
// @lc code=start
class MyStack {
    queue<int> q1;
    queue<int> q2;

  public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        } else {
            q2.push(x);
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = 0;
        if (q1.empty()) {
            t = q2.front();
            q2.pop();
        } else {
            t = q1.front();
            q1.pop();
        }
        return t;
    }

    /** Get the top element. */
    int top() {
        if (q1.empty()) {
            return q2.front();
        } else {
            return q1.front();
        }
    }

    /** Returns whether the stack is empty. */
    bool empty() { return q1.empty() && q2.empty(); }
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

// 若只使用一个队列

class MyStack2 {
    queue<int> q;
    int size;

  public:
    /** Initialize your data structure here. */
    MyStack2() { size = 0; }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int tmp = 0;
        for (int i = 0; i < size; i++) {
            tmp = q.front();
            q.push(tmp);
            q.pop();
        }
        size++;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = q.front();
        q.pop();
        size--;
        return t;
    }

    /** Get the top element. */
    int top() { return q.front(); }

    /** Returns whether the stack is empty. */
    bool empty() { return q.empty(); }
};