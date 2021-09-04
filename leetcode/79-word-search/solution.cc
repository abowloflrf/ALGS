/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (45.74%)
 * Likes:    1010
 * Dislikes: 0
 * Total Accepted:    213.2K
 * Total Submissions: 466.1K
 * Testcase Example:  '[['A',"B",'C','E'],['S','F','C','S'],['A','D','E','E']]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *
 *
 * Example 1:
 *
 *
 * Input: board = [['A',"B",'C','E'],['S','F','C','S'],['A','D','E','E']], word
 * = "ABCCED"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: board = [['A',"B",'C','E'],['S','F','C','S'],['A','D','E','E']], word
 * = "SEE"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: board = [['A',"B",'C','E'],['S','F','C','S'],['A','D','E','E']], word
 * = "ABCB"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 *
 *
 *
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        height = board.size();
        width = board.front().size();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (dfs(i, j, board, word, 0))
                    return true;
            }
        }
        return false;
    }

  private:
    int height = 0;
    int width = 0;
    // 从 [x][y] 位置出发能否找到 从 idx 位置开始的 word 字符串路径
    bool dfs(int x, int y, vector<vector<char>> &board, string &word, int idx) {
        // 先判断是否出界
        if (x >= height || x < 0 || y >= width || y < 0)
            return false;
        // 当前字符不匹配直接 return false
        if (board[x][y] != word[idx])
            return false;
        // 当前字符匹配且已经是最后一位
        if (idx == word.size() - 1)
            return true;

        // 不能往回走，将走过的路径变为 0
        // 然后再上下左右四个方向找，任意一个方向找到都算 ok
        char old = board[x][y];
        board[x][y] = '0';
        bool found = dfs(x - 1, y, board, word, idx + 1) || dfs(x + 1, y, board, word, idx + 1) ||
                     dfs(x, y - 1, board, word, idx + 1) || dfs(x, y + 1, board, word, idx + 1);
        // 回溯
        board[x][y] = old;
        return found;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<vector<char>> boars = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution s;
    s.exist(boars, "ABCCED");
    return 0;
}
