/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (39.89%)
 * Likes:    3269
 * Dislikes: 48
 * Total Accepted:    239K
 * Total Submissions: 567.7K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 *
 * You have the following 3 operations permitted on a word:
 *
 *
 * Insert a character
 * Delete a character
 * Replace a character
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation:
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation:
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start

/**
 * 子问题：dp[i][j]，word1 前i个字符 转为 word2 前j个字符需要的步数
 * 初始化：i=0时 dp[0][j] == j  j=0时 dp[i][0] == i
 * if word1[i] == word2[j]:
 *     dp[i][j] = dp[i-1][j-1]
 * else:
 *     dp[i][j] = min(dp[i-1][j],dp[i][j-1] ,dp[i-1][j-1]) + 1
 **/
class Solution {
  public:
    int minDistance(string word1, string word2) {
        // vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        int dp[word1.size() + 1][word2.size() + 1];
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); i++)
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                }
            }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end
