/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] Reverse Bits
 *
 * https://leetcode-cn.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (69.61%)
 * Likes:    427
 * Dislikes: 0
 * Total Accepted:    128K
 * Total Submissions: 183.8K
 * Testcase Example:  '00000010100101000001111010011100'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * Note:
 *
 *
 * Note that in some languages such as Java, there is no unsigned integer type.
 * In this case, both input and output will be given as a signed integer type.
 * They should not affect your implementation, as the integer's internal binary
 * representation is the same, whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 2 above, the input represents the signed
 * integer -3 and the output represents the signed integer -1073741825.
 *
 *
 * Follow up:
 *
 * If this function is called many times, how would you optimize it?
 *
 *
 * Example 1:
 *
 *
 * Input: n = 00000010100101000001111010011100
 * Output:    964176192 (00111001011110000010100101000000)
 * Explanation: The input binary string 00000010100101000001111010011100
 * represents the unsigned integer 43261596, so return 964176192 which its
 * binary representation is 00111001011110000010100101000000.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 11111111111111111111111111111101
 * Output:   3221225471 (10111111111111111111111111111111)
 * Explanation: The input binary string 11111111111111111111111111111101
 * represents the unsigned integer 4294967293, so return 3221225471 which its
 * binary representation is 10111111111111111111111111111111.
 *
 *
 *
 * Constraints:
 *
 *
 * The input must be a binary string of length 32
 *
 *
 */
#include <cstdint>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        // queue<int> pos;
        // int idx = 0;
        // for (int i = 1; i <= 32; i++) {
        //     if (n & 1) {
        //         pos.push(i);
        //     }
        //     n >>= 1;
        // }

        // uint32_t nn = 0;
        // for (int i = 1; i <= 32; i++) {
        //     nn <<= 1;
        //     if (pos.front() == i) {
        //         nn++;
        //         pos.pop();
        //     }
        // }
        // return nn;

        // 更简洁
        uint32_t ans = 0;
        int i = 32;
        while (i--) {
            ans <<= 1;
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};
// @lc code=end
