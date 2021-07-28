#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isPopOrder(vector<int> orderPush, vector<int> orderPop) {
    stack<int> tempStack;
    while (!(orderPush.empty() && tempStack.empty())) {
        bool hasOpration = false;
        if (!tempStack.empty())
            while (tempStack.top() == orderPop.front()) {
                hasOpration = true;
                tempStack.pop();
                orderPop.erase(orderPop.begin());
                if (tempStack.empty())
                    break;
            }

        //队列之一为空
        if (orderPop.empty() || orderPush.empty()) {
            if (!hasOpration)
                break;
            continue;
        }
        //两队列都不为空
        if (orderPush.front() != orderPop.front()) {
            hasOpration = true;
            tempStack.push(orderPush.front());
            orderPush.erase(orderPush.begin());
        } else if (orderPush.front() == orderPop.front()) {
            hasOpration = true;
            orderPush.erase(orderPush.begin());
            orderPop.erase(orderPop.begin());
        }
        if (!hasOpration)
            break;
    }
    if (orderPush.empty() && orderPop.empty())
        return true;
    if (orderPush.empty() || orderPop.empty())
        return false;
}

class Solution {
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        if (pushed.size() != popped.size()) {
            return false;
        }

        std::stack<int> s;
        int popIdx = 0;
        for (auto i : pushed) {
            s.push(i);
            while (!s.empty() && popIdx < popped.size() && s.top() == popped[popIdx]) {
                s.pop();
                popIdx++;
            }
        }
        return s.empty() && popIdx == popped.size();
    }
};

int main() {
    Solution s;
    vector<int> orderPush = {1, 2, 3, 4, 5};
    vector<int> orderPop_1 = {4, 3, 5, 1, 2};
    vector<int> orderPop_2 = {4, 5, 3, 2, 1};

    vector<int> tmp1{1, 0};
    vector<int> tmp2{1, 0};
    // s.validateStackSequences(orderPush, orderPop_1);
    // s.validateStackSequences(orderPush, orderPop_2);
    s.validateStackSequences(tmp1, tmp2);
    bool resultB = isPopOrder(orderPush, orderPop_2);
    bool resultA = isPopOrder(orderPush, orderPop_1);
    cout << resultA << "-" << resultB;
    return 0;
}