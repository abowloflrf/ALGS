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
            // if (s[i] == ' ') continue;
            char c = s[i];
            //遇到数字，与前面一位数字合并进位
            if (c >= '0' && c <= '9') num = num * 10 + (c - '0');
            //若不是数字，即遇到运算符
            if ((c != ' ' && !(c >= '0' && c <= '9')) || i + 1 == s.length()) {
                //这里先结算上一个运算符的结果
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
                //保存当前运算符，后面的数字计算完成后再进入这个if完成运算
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