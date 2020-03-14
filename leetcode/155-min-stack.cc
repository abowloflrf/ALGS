/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (39.32%)
 * Likes:    2708
 * Dislikes: 278
 * Total Accepted:    421.5K
 * Total Submissions: 1M
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *
 *
 *
 *
 * Example:
 *
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 *
 *
 *
 */
#include <stack>
using namespace std;
// @lc code=start
class MinStack {
  public:
    /** initialize your data structure here. */
    MinStack() {
        data = {};
        minStack = {};
    }

    void push(int x) {
        if (data.empty() || x <= minStack.top())
            minStack.push(x);
        data.push(x);
    }

    void pop() {
        if (minStack.top() == data.top())
            minStack.pop();
        data.pop();
    }

    int top() { return data.top(); }

    int getMin() {
        if (data.size() == 0)
            return -1;
        return minStack.top();
    }

  private:
    stack<int> data;
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main(){
    MinStack *m = new MinStack();
    m->push(1);
    m->push(2);
    m->push(3);
    m->push(1);
    m->pop();
    int t = m->top();
}