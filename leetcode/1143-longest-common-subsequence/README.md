# 1143. 最长公共子序列

### 动态规划

`dp[i][j]` 为 s1 前 i 个字符和 s2 前 j 个字符的最长公共子序列

-   最终结果为 `dp[i][j]`
-   i 或 j 为 0 时，`dp[i][j]` 为 0

若末尾字符相等 `s1[i]==s2[j]` 则最后这个字符一定在最最长公共子序列中，可得到如下状态转移方程

### 状态转移方程

1. 末尾字符 `s1[i]==s2[j]` 相等时：

```
dp[i][j] = dp[i-1][j-1] + 1 (s1[i]==s2[j])
```

2. 末尾字符 `s1[i]!=s2[j]` 不等时：

```
dp[i][j] = max(dp[i-1][j], dp[j-1][i])
```

### 代码实现

```c++
class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
```

### 复杂度分析

-   时间复杂度 `O(m*n)`
-   空间复杂度 `O(m*n)`
