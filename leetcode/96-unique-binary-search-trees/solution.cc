/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (69.89%)
 * Likes:    1271
 * Dislikes: 0
 * Total Accepted:    149.2K
 * Total Submissions: 213.4K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of structurally unique BST's (binary
 * search trees) which has exactly n nodes of unique values from 1 to n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: 5
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
 * 1 <= n <= 19
 *
 *
 */

// @lc code=start
class Solution {
  public:
    int numTrees(int n) {
        int G[n + 1];
        for (int i = 0; i < n + 1; i++)
            G[i] = 0;
        G[0] = 1;
        G[1] = 1;

        // G[2] = G[0]*G[1] + G[1]*G[0]
        // G[3] = G[0]*G[2] + G[1]*G[1] + G[2]*G[0]
        for (int i = 2; i < n + 1; i++) {
            for (int j = 0; j < i; j++) {
                G[i] = G[i] + G[j] * G[i - j - 1];
            }
        }
        return G[n];
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {

    Solution s;
    s.numTrees(3);
    return 0;
}
