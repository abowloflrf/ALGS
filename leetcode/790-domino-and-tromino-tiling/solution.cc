/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 *
 * https://leetcode.cn/problems/domino-and-tromino-tiling/description/
 *
 * algorithms
 * Medium (53.78%)
 * Likes:    346
 * Dislikes: 0
 * Total Accepted:    30.9K
 * Total Submissions: 57.4K
 * Testcase Example:  '3'
 *
 * You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You
 * may rotate these shapes.
 *
 * Given an integer n, return the number of ways to tile an 2 x n board. Since
 * the answer may be very large, return it modulo 10^9 + 7.
 *
 * In a tiling, every square must be covered by a tile. Two tilings are
 * different if and only if there are two 4-directionally adjacent cells on the
 * board such that exactly one of the tilings has both squares occupied by a
 * tile.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: 5
 * Explanation: The five different ways are show above.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1000
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int numTilings(int n) {
        int mod = 1e9 + 7;
        if (n == 1)
            return 1;
        long a = 1, b = 1, c = 2;
        for (int i = 3; i <= n; ++i) {
            long f = (c * 2 + a) % mod;
            a = b;
            b = c;
            c = f;
        }
        return c;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    int ans = s.numTilings(5);
    return 0;
}
