#include <stack>
#include <string>
using namespace std;
class Solution {
   public:
    bool isValid(string s) {
        if (s == "") return true;
        int index = 0;
        stack<char> mStack;
        for (char &c : s) {
            if (mStack.empty()) {
                mStack.push(c);
            } else {
                int flag = abs(mStack.top() - c);
                if (flag != 0 && flag <= 2)
                    mStack.pop();
                else
                    mStack.push(c);
            }
        }
        if (mStack.empty()) return true;
        return false;
    }
};