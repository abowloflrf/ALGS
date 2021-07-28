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
        maxLen = 1;
    }
    string longestPalindrome(string s) {
        int length = s.length();
        if (length < 2)
            return s;
        for (int i = 0; i < length - 1; i++) {
            findPalindrome(s, i, i);
            findPalindrome(s, i, i + 1);
        }
        return s.substr(index, maxLen);
    }

  private:
    int index;  // 最大长度时的字符串起点位置
    int maxLen; // 最大长度
    // 对于字符串s，中心字符位置是left和right时，计算此情况的最长回文串
    void findPalindrome(string s, int left, int right) {
        if (s[left] != s[right])
            return;
        // 剪枝：预先计算这组情况理想情况时可能的最长回文串mLen，若比当前maxLen都小就可以直接跳过了
        int mLen = 2 * min(left + 1, int(s.size()) - right);
        if (left == right)
            mLen--;
        if (maxLen >= mLen)
            return;

        // 先判断中间maxLen长度是否符合，必须全部符号才能继续往下走，否则直接return
        int currLen = right - left + 1; // 奇数长度和偶数长度分别为1或2
        left--;
        right++;
        while (currLen <= mLen && left >= 0 && right < s.size()) {
            if (s[left] != s[right])
                break;
            currLen += 2;
            if (currLen > maxLen) {
                maxLen = currLen;
                index = left;
            }
            left--;
            right++;
        }
        if (currLen > maxLen) {
            maxLen = currLen;
            index = left + 1;
        }
    }
};

int main(int argc, char const *argv[]) {
    string str = "cbbd";
    Solution s;
    cout << s.longestPalindrome(str) << endl;
    return 0;
}