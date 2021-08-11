/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (54.44%)
 * Likes:    652
 * Dislikes: 0
 * Total Accepted:    184K
 * Total Submissions: 337.9K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 *
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 *
 * Constraints:
 *
 *
 * 1 <= a.length, b.length <= 10^4
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    string addBinary(string a, string b) {
        vector<char> res;
        int size = a.size();
        if (b.size() > size)
            size = b.size();
        bool flag = false;
        for (int i = 0; i < size; i++) {
            int idxa = a.size() - i - 1;
            int idxb = b.size() - i - 1;
            if (idxa >= 0 && idxb >= 0) {
                if (a[idxa] == '1' && b[idxb] == '1') {
                    if (flag) {
                        res.push_back('1');
                    } else {
                        res.push_back('0');
                    }
                    flag = true;
                } else if (a[idxa] == '0' && b[idxb] == '0') {
                    if (flag) {
                        res.push_back('1');
                    } else {
                        res.push_back('0');
                    }
                    flag = false;
                } else {
                    if (flag) {
                        res.push_back('0');
                        flag = true;
                    } else {
                        res.push_back('1');
                    }
                }
            } else if (idxa >= 0 || idxb >= 0) {
                char x = ' ';
                if (idxa >= 0)
                    x = a[idxa];
                else
                    x = b[idxb];
                if (x == '0') {
                    if (flag) {
                        res.push_back('1');
                        flag = false;
                    } else {
                        res.push_back('0');
                    }
                } else {
                    if (flag) {
                        res.push_back('0');
                        flag = true;
                    } else {
                        res.push_back('1');
                    }
                }
            }
        }
        if (flag) {
            res.push_back('1');
        }
        string str;
        for (int i = res.size() - 1; i >= 0; i--) {
            str += res[i];
        }
        return str;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    s.addBinary("110010", "10111");
    return 0;
}
