//
// Created by ruofeng on 2018/7/30.
//

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
        //stack中保存的是所有无效的括号位置
        stack<int> mStack;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                mStack.push(i);
            else if (s[i] == ')' && !mStack.empty() && s[mStack.top()] == '(')
                mStack.pop();
            else
                mStack.push(i);
        }
        //stack中无效括号位置之间为有效的位置，计算最大间隔即可
        if (mStack.empty())
            return s.length();
        int maxLength = s.length() - mStack.top() - 1;
        while (!mStack.empty()) {
            int t1 = mStack.top();
            mStack.pop();
            if (mStack.empty()) {
                maxLength = max(maxLength, t1);
            } else {
                int t2 = mStack.top();
                maxLength = max(maxLength, t1 - t2 - 1);
            }
        }
        return maxLength;
    }
    int longestValidParentheses2(string s) {
        stack<int> mStack;
        int maxLength = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!mStack.empty() && s[i] == ')' && s[mStack.top()] == '(') {
                mStack.pop();
                //栈空说明此位置之前的字符串都是有效括号对
                if (mStack.empty())
                    maxLength = i + 1;
                else {
                    //栈非空则此时最大长度为当前位置到前一个还未出栈即未匹配到括号的位置的距离
                    maxLength = max(maxLength, i - mStack.top());
                }
            } else
                mStack.push(i);
        }
        return maxLength;
    }
};

int main() {
    Solution s;
    s.longestValidParentheses2("()");
    return 0;
}