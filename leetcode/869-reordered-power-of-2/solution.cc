/*
 * @lc app=leetcode.cn id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 *
 * https://leetcode-cn.com/problems/reordered-power-of-2/description/
 *
 * algorithms
 * Medium (55.32%)
 * Likes:    52
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 13.5K
 * Testcase Example:  '1'
 *
 * You are given an integer n. We reorder the digits in any order (including
 * the original order) such that the leading digit is not zero.
 *
 * Return true if and only if we can do this so that the resulting number is a
 * power of two.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: n = 10
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: n = 16
 * Output: true
 *
 *
 * Example 4:
 *
 *
 * Input: n = 24
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: n = 46
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^9
 *
 *
 */
#include <cmath>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool reorderedPowerOf2(int n) {
        int len = 0;
        vector<int> data;
        while (n) {
            int t = n % 10;
            data.push_back(t);
            n = (n - t) / 10;
            len++;
        }
        sort(data.begin(), data.end());

        // 长度为 len
        // 计算 10^len - 10^10-1 范围内的所有符合条件 2^k 的 k
        // 并与 data 比较
        vector<int> valid;
        int tmp = 1;
        int minK = pow(10, len - 1), maxK = pow(10, len) - 1;
        while (tmp <= maxK) {
            if (tmp >= minK) {
                valid.push_back(tmp);
            }
            tmp <<= 1;
        }
        // 对每个 valid 和 data 中的数字进行比较
        for (auto v : valid) {
            vector<int> tmp;
            while (v) {
                int t = v % 10;
                tmp.push_back(t);
                v = (v - t) / 10;
            }
            sort(tmp.begin(), tmp.end());
            bool flag = true;
            for (int i = 0; i < len; i++) {
                if (tmp[i] != data[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    s.reorderedPowerOf2(46);
    return 0;
}
