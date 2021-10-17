/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] Number Complement
 *
 * https://leetcode-cn.com/problems/number-complement/description/
 *
 * algorithms
 * Easy (70.11%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    39.4K
 * Total Submissions: 56K
 * Testcase Example:  '5'
 *
 * The complement of an integer is the integer you get when you flip all the
 * 0's to 1's and all the 1's to 0's in its binary representation.
 *
 *
 * For example, The integer 5 is "101" in binary and its complement is "010"
 * which is the integer 2.
 *
 *
 * Given an integer num, return its complement.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits),
 * and its complement is 010. So you need to output 2.
 *
 *
 * Example 2:
 *
 *
 * Input: num = 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and
 * its complement is 0. So you need to output 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num < 2^31
 *
 *
 *
 * Note: This question is the same as 1009:
 * https://leetcode.com/problems/complement-of-base-10-integer/
 *
 */

// @lc code=start
class Solution {
  public:
    int findComplement(int num) {
        int ans = 0;
        int count = 0;
        // 10 = 1010 -> 0101 -> 5
        while (num) {
            if (!(num & 1)) {
                ans = ans + (1 << count);
            }
            count++;
            num >>= 1;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    s.findComplement(10);
    return 0;
}
