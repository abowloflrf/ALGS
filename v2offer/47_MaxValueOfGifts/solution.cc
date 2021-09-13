#include <vector>
using namespace std;

// dp
// dp[i][j] 为从出发点到 i,j 位置能获得的最大礼物值
// f(i,j)=max[f(i,j−1),f(i−1,j)]+grid(i,j)
class Solution {
  public:
    int maxValue(vector<vector<int>> &grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid.front().size(), 0));
        // f(i,j) = max[f(i,j−1),f(i−1,j)]+grid(i,j)
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid.front().size(); i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < grid.size(); i++)
            for (int j = 1; j < grid.front().size(); j++) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        return dp.back().back();
    }
};

// 直接 dfs，超时
class Solution2 {
  public:
    int maxValue(vector<vector<int>> &grid) { return dfs(grid, 0, 0, grid[0][0]); }
    int dfs(vector<vector<int>> &grid, int x, int y, int current) {
        if (x == grid.size() - 1) {
            for (int i = y + 1; i < grid.front().size(); i++) {
                current += grid[x][i];
            }
            return current;
        }
        if (y == grid.front().size() - 1) {
            for (int i = x + 1; i < grid.size(); i++) {
                current += grid[i][y];
            }
            return current;
        }
        return max(dfs(grid, x + 1, y, current + grid[x + 1][y]), dfs(grid, x, y + 1, current + grid[x][y + 1]));
    }
};