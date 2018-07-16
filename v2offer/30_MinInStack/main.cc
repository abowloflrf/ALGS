#include <iostream>
#include <stack>
using namespace std;

class MinStack {
   private:
    stack<int> mStack;
    stack<int> minValues;

   public:
    /** initialize your data structure here. */
    MinStack() {
        mStack = {};
        minValues = {};
    }

    void push(int x) {
        if (mStack.empty() || x <= minValues.top()) minValues.push(x);
        mStack.push(x);
    }

    void pop() {
        if (mStack.empty()) return;
        if (mStack.top() == minValues.top()) minValues.pop();
        mStack.pop();
    }

    int top() { return mStack.top(); }

    int getMin() { return minValues.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
    MinStack myStack = MinStack();
    myStack.push(-2);
    myStack.push(0);
    myStack.push(-1);
    int a = myStack.getMin();
    myStack.pop();
    myStack.push(-10);
    int b = myStack.getMin();
    myStack.pop();
    int c = myStack.getMin();
    return 0;
}