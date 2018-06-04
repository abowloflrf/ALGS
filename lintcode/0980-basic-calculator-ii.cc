/**
 * 使用stack数据结构是关键，每次入栈前计算将要入栈的数为num
 * 若遇到连续的数字则`num=num*10+c-'0'`
 * 若遇到`+`则将计算的数入栈并将其归零
 * 若遇到`-`则将`-num`入栈
 * 若遇到`*`则出栈并将其与num相乘再入栈
 * 若遇到`/`则出栈再将其与计算的num相除再入栈
 * 最终循环将栈内的所有数相加
 */

#include <stack>
#include <string>
using namespace std;

class Solution {
   public:
    /**
     * @param s: the given expression
     * @return: the result of expression
     */
    int calculate(string &s) {
        stack<int> mStack;
        char flag = '+';
        int num = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            char c = s[i];
            if (c >= '0' && c <= '9') num = num * 10 + (c - '0');
            //若不是数字，即遇到运算符
            if (!(c >= '0' && c <= '9') || i + 1 == s.length()) {
                if (flag == '+')
                    mStack.push(num);
                else if (flag == '-')
                    mStack.push(-num);
                else if (flag == '*') {
                    int temp = mStack.top();
                    mStack.pop();
                    mStack.push(temp * num);
                } else if (flag == '/') {
                    int temp = mStack.top();
                    mStack.pop();
                    mStack.push(temp / num);
                }
                flag = c;
                num = 0;
                continue;
            }
        }
        int res = 0;
        while (!mStack.empty()) {
            res += mStack.top();
            mStack.pop();
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    string str = "3-89*21";
    int res = s.calculate(str);
    return 0;
}