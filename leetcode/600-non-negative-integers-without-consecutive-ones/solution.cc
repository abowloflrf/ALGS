/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 *
 * https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/description/
 *
 * algorithms
 * Hard (35.91%)
 * Likes:    118
 * Dislikes: 0
 * Total Accepted:    4.5K
 * Total Submissions: 12.6K
 * Testcase Example:  '5'
 *
 * Given a positive integer n, return the number of the integers in the range
 * [0, n] whose binary representations do not contain consecutive ones.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5
 * Output: 5
 * Explanation:
 * Here are the non-negative integers <= 5 with their corresponding binary
 * representations:
 * 0 : 0
 * 1 : 1
 * 2 : 10
 * 3 : 11
 * 4 : 100
 * 5 : 101
 * Among them, only integer 3 disobeys the rule (two consecutive ones) and the
 * other 5 satisfy the rule.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: n = 2
 * Output: 3
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

// @lc code=start
class Solution {
  public:
    int findIntegers(int n) {
        // xxxx11 ^ 3 == 0
        int count = 0;
        for (int i = 0; i <= n; i++) {
            if (valid(i))
                count++;
        }
        return count;
    }

  private:
    bool valid(int n) {
        while (n) {
            if (((n & 3) ^ 3) == 0)
                return false;
            n >>= 1;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    Solution s;
    int a = s.findIntegers(7);
    return 0;
}
