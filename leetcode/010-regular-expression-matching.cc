//
// Created by ruofeng on 2018/7/29.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        //只看第一位，是否匹配
        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        //若表达式的第二位是*则可以选择匹配或不匹配
        if (p.length() > 1 && p[1] == '*')
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        else
            //否则继续向后匹配
            return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
};

int main() {
    Solution s;

    cout << s.isMatch("ab", ".*c") << endl;
    return 0;
}