/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (43.32%)
 * Likes:    2198
 * Dislikes: 169
 * Total Accepted:    250.1K
 * Total Submissions: 559.1K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
#include <cmath>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
  public:
    int numSquares(int n) {
        int mem[n + 1];
        mem[0] = 0;
        for (int i = 1; i <= n; i++) {
            mem[i] = i;
            int j = 1;
            int m = i - j * j;
            while (true) {
                if (m < 0)
                    break;
                mem[i] = min(mem[i], mem[m] + 1);
                j++;
                m = i - j * j;
            }
        }
        return mem[n];
    }
};
// @lc code=end

// 这个慢一点
class Solution2 {
  public:
    int numSquares(int n) {
        int mem[n + 1];
        for (int i = 0; i < n + 1; i++) {
            mem[i] = INT32_MAX;
        }
        mem[0] = 0;
        return dp(mem, n, n);
    }

  private:
    int dp(int mem[], int n, int target) {
        if (mem[target] != INT32_MAX)
            return mem[target];

        mem[target] = target;
        int i = 1;
        while (true) {
            int m = target - i * i;
            if (m < 0)
                break;
            mem[target] = min(mem[target], dp(mem, n, m) + 1);
            i++;
        }
        return mem[target];
    }
};

int main() {
    Solution s;
    int r = s.numSquares(4);
    return 0;
}