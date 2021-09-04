
#include <vector>
using namespace std;
class Solution {
  public:
    // 从 [0][0] 移动到 [m-1][n-1] ，每次可上下左右移动一格，但不能进入 x y 各位数字之和大于 k 的位置
    // 一共可以到达多少个格子

    // 先把地图不可达的点标记一遍
    // 再 dfs
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> board(m, vector<bool>(n, false));
        return dfs(0, 0, board, k);
    }

  private:
    bool validPath(int x, int y, int k) {
        int xx = 0, yy = 0;
        while (x) {
            xx += x % 10;
            x /= 10;
        }
        while (y) {
            yy += y % 10;
            y /= 10;
        }
        if (xx + yy > k)
            return false;
        return true;
    }
    int dfs(int x, int y, vector<vector<bool>> &board, int k) {
        if (x >= board.size() || y >= board.front().size() || x < 0 || y < 0)
            return 0;
        if (board[x][y] || !validPath(x, y, k))
            return 0;
        board[x][y] = true;
        return 1 + dfs(x + 1, y, board, k) + dfs(x, y + 1, board, k);
    }
};
