/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (71.08%)
 * Likes:    1539
 * Dislikes: 149
 * Total Accepted:    284.2K
 * Total Submissions: 399.3K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 ≤ x, y < 2^31.
 *
 *
 * Example:
 *
 * Input: x = 1, y = 4
 *
 * Output: 2
 *
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 *
 * The above arrows point to positions where the corresponding bits are
 * different.
 *
 *
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    int hammingDistance(int x, int y) {
        int r = x ^ y; //异或
        // 然后计算二进制结果中1的个数
        unsigned int count = 0;
        while (r) {
            count += r & 1;
            r >>= 1;
        }
        return count;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.hammingDistance(1, 4);
}
