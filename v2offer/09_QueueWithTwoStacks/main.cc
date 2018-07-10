#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class CQueue {
   public:
    void appendTail(const T& node);  //从队尾入队
    T deleteHead();                  //从队首出队
   private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T& node) {
    stack1.push(node);
}

//这个是实现比较差的版本
//缺点：每次出队复杂度较高，两个栈的容量利用只有一半
// template <typename T>
// T CQueue<T>::deleteHead() {
//     int size = stack1.size();
//     for (int i = 0; i < size - 1; i++) {
//         stack2.push(stack1.top());
//         stack1.pop();
//     }
//     T target = stack1.top();
//     stack1.pop();
//     for (int i = 0; i < size - 1; i++) {
//         stack1.push(stack2.top());
//         stack2.pop();
//     }
//     return target;
// }

//下面是较为优秀的版本
//两个栈的容量均得到利用
//其中 stack2 的顶部为队列尾部
//出队时若 stack2 不为空则弹出顶部，若为空，则将 stack1 转移到 stack2
//每次入队加入到 stack1 的顶部
template <typename T>
T CQueue<T>::deleteHead() {
    // stack2为空则将stack1的内容全部转移到stack2
    if (stack2.empty()) {
        while (!stack1.empty()) {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if (stack2.empty()) {
        cout << "CQueue is empty!" << endl;
        exit;
    }
    T head = stack2.top();
    stack2.pop();
    return head;
}

int main() {
    CQueue<int> myQueue;
    myQueue.appendTail(1);
    myQueue.appendTail(2);
    myQueue.appendTail(3);
    int tail = myQueue.deleteHead();
    cout << tail << endl;
    return 0;
}