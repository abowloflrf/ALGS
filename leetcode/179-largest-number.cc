/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (26.76%)
 * Likes:    1529
 * Dislikes: 184
 * Total Accepted:    161.9K
 * Total Submissions: 587.4K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 *
 * Example 1:
 *
 *
 * Input: [10,2]
 * Output: "210"
 *
 * Example 2:
 *
 *
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start

// 按照最高位依次比较
bool cmp(string a, string b) { return a + b > b + a; }

class Solution {
  public:
    string largestNumber(vector<int> &nums) {
        if (nums.empty())
            return "0";
        vector<string> strs;
        for (int n : nums)
            strs.push_back(to_string(n));
        sort(strs.begin(), strs.end(), cmp);
        string res;
        for (string s : strs) {
            res += s;
        }
        if (res[0] == '0')
            return "0";
        return res;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {3, 30, 34, 5, 9};
    string ret = s.largestNumber(v);
    return 0;
}