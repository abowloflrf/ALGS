/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (41.91%)
 * Likes:    1227
 * Dislikes: 2070
 * Total Accepted:    520K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 *
 *
 * Example 2:
 *
 *
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 *
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int pos = digits.size() - 1;
        while (pos != -1) {
            if (++digits[pos] == 10) {
                digits[pos] = 0;
                pos--;
            } else {
                break;
            }
        }
        if (pos == -1) {
            vector<int> res = {1};
            res.insert(res.end(), digits.begin(), digits.end());
            return res;
        }
        return digits;
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> vec{9,9};
    auto r = s.plusOne(vec);
    return 0;
}
