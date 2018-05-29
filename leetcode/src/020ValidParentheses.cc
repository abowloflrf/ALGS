#include <stack>
#include <string>
using namespace std;
class Solution {
   public:
    bool isValid(string s) {
        if (s == "") return true;
        stack<char> mStack;
        for (char &c : s) {
            if (c == '{' || c == '[' || c == '(')
                mStack.push(c);
            else if (c == '}') {
                if (mStack.empty() || mStack.top() != '{') return false;
                mStack.pop();
            } else if (c == ']') {
                if (mStack.empty() || mStack.top() != '[') return false;
                mStack.pop();
            } else if (c == ')') {
                if (mStack.empty() || mStack.top() != '(') return false;
                mStack.pop();
            }
        }
        return mStack.empty();
    }
};