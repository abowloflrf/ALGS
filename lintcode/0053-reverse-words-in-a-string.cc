#include <iostream>
#include <string>
using namespace std;
class Solution {
   public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s) {
        // write your code here
        int size = s.size();
        string res = "";
        string appendStr = "";
        for (int i = 0; i < size; i++) {
            //清除头部空字符
            if (appendStr.empty() && s[i] == ' ') continue;
            //字符串中间的空格若有多个，减少到一个
            if (s[i] == ' ') {
                if (appendStr.empty())
                    continue;
                else {
                    res = (res.empty() ? appendStr : appendStr + " ") + res;
                    appendStr = "";
                }
            } else {
                appendStr += s[i];
            }
        }
        if (!appendStr.empty()) res = appendStr + " " + res;
        return res;
    }
};

int main() {
    Solution s = Solution();
    string str = "  i love   you";
    string res = s.reverseWords(str);
    cout << res << endl;
    return 0;
}