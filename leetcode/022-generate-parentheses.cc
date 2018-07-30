//
// Created by ruofeng on 2018/7/30.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        generate("", n, 0);
        return res;
    }
  private:
    /**
     *
     * @param s 生成的括号对字符串
     * @param m 待入栈的括号数量
     * @param n 已经入栈的括号中待出栈的括号数量
     */
    void generate(string s, int m, int n) {
        if (m == 0 && n == 0) {
            res.push_back(s);
            return;
        }
        if (m > 0)
            generate(s + '(', m - 1, n + 1);
        if (n > 0)
            generate(s + ')', m, n - 1);
    }
    vector<string> res;
};

int main() {
    Solution s;
    for (auto i:s.generateParenthesis(3))
        cout << i << endl;
    return 0;
}