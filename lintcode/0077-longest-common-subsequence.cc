// LCS 两个字符串的最长公共子序列

#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
        int m = A.size();
        int n = B.size();
        vector<vector<int>> dp(1 + m, vector<int>(1 + n));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    string s1 = "ABCD";
    string s2 = "EACB";
    int res = s.longestCommonSubsequence(s1, s2);
    return 0;
}
