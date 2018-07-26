//最长回文子串

#include <iostream>
#include <string>

using namespace std;

// class Solution {
//    public:
//     Solution() {
//         index = 0;
//         maxLen = 0;
//     }
//     string longestPalindrome(string s) {
//         int length = s.length();
//         for (int i = 0; i < length; i++) {
//             findPalindrome(s, i);
//         }
//         return s.substr(index, maxLen);
//     }

//    private:
//     int index;
//     int maxLen;
//     void findPalindrome(string s, int pos) {
//         //若这个位置可能得到的最长回文串已经小于目前的最大值，则直接返回
//         if ((int)(s.size() - pos + 1) <= maxLen) return;
//         //寻找在字符串s中以i开头的回文串
//         bool isPalindrome = true;
//         for (int l = maxLen + 1; l <= s.size() - pos + 1; l++) {
//             for (int i = pos; i <= pos + l / 2; i++) {
//                 if (s[i] != s[2 * pos + l - i - 1]) {
//                     isPalindrome = false;
//                     break;
//                 }
//             }
//             if (isPalindrome) {
//                 maxLen = l;
//                 index = pos;
//             }
//             isPalindrome = true;
//         }
//     }
// };

//这个solution的pos是回文的中间位置
class Solution {
   public:
    Solution() {
        index = 0;
        maxLen = 0;
    }
    string longestPalindrome(string s) {
        int length = s.length();
        if (length < 2) return s;
        for (int i = 0; i < length - 1; i++) {
            findPalindrome(s, i, i);
            findPalindrome(s, i, i + 1);
        }
        return s.substr(index, maxLen);
    }

   private:
    int index;
    int maxLen;
    void findPalindrome(string s, int left, int right) {
        if (s[left] != s[right]) return;
        //计算mLen，可能的最大值
        int mLen = 2 * min(left + 1, (int)s.size() - right);
        if (left == right) mLen--;
        if (maxLen >= mLen) return;
        //先判断中间maxLen长度是否符合
        int currLen = right - left + 1;
        while (currLen <= maxLen) {
            if (s[left--] != s[right++]) return;
            currLen += 2;
        }
        //再判断外面
        while (currLen <= mLen) {
            if (s[left] != s[right]) break;
            //记录
            index = left;
            maxLen = currLen;
            //向外扩展
            left--;
            right++;
            currLen += 2;
        }
    }
};

int main(int argc, char const *argv[]) {
    // string str = "babad";
    Solution s;
    cout << s.longestPalindrome(argv[1]) << endl;
    return 0;
}