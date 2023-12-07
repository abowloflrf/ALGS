#include <queue>
#include <stack>
using namespace std;

class MaxStack {
  private:
    priority_queue<int> q;
    int lastElem;

  public:
    MaxStack() {}

    void push(int x) {
        q.push(x);
        lastElem = x;
    }

    int pop() {
        q.
    }

    int top() {}

    int peekMax() {}

    int popMax() {}
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */

int main(int argc, char const *argv[]) {

    MaxStack *m = new MaxStack();
    m->push(5);
    m->push(1);
    m->popMax();
    m->peekMax();
    return 0;
}
