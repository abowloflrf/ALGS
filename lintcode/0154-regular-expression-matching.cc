#include <iostream>
#include <string>
using namespace std;
class Solution {
   public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();

        //首个字母匹配
        bool firstMatch = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

        if (p.size() >= 2 && p[1] == '*') {
            // reg长度大于2且第二位是*时，一定会匹配，因此可以有
            // 1. 当作*匹配到0位，reg表达式去掉前两位再匹配
            // 2. 因为*可以匹配任意多位，若首字母匹配则去掉str前面一位再匹配
            return (isMatch(s, p.substr(2)) ||
                    (firstMatch && isMatch(s.substr(1), p)));
        } else {
            //第二位没有*时，从第二位开始匹配
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main() {
    Solution s;
    string str = "aa";
    string reg = "a*";
    bool res = s.isMatch(str, reg);
    return 0;
}