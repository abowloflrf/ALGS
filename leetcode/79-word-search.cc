/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (32.72%)
 * Likes:    2856
 * Dislikes: 147
 * Total Accepted:    400K
 * Total Submissions: 1.2M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 *
 * Example:
 *
 *
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 *
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
        if (height == 0)
            return false;
        width = board[0].size();
        if (width == 0)
            return false;
        for (int i = 0; i < width; i++)
            for (int j = 0; j < height; j++)
                if (search(i, j, 0, board, word))
                    return true;
        return false;
    }

  private:
    int width;
    int height;
    // d 为当前单词的第几位
    bool search(int x, int y, int d, vector<vector<char>> &board, string &word) {
        // 先判断目标坐标是否超出边界
        if (x == width || x < 0 || y == height || y < 0)
            return false;
        // 不相等直接退出
        if (board[y][x] != word[d])
            return false;
        // 找到相等且是最后以为，成功
        if (d == word.size() - 1)
            return true;
        // 找到相等但是不是最后以为，继续向四个方向找
        // TIPS: 因为题目要求不允许往回走，因此将当前走到的格子字符变为0（永远不会被匹配到）
        // 找完四个方向之后再填回原来的字符
        char curr = board[y][x];
        board[y][x] = 0;
        bool found = search(x + 1, y, d + 1, board, word) || search(x - 1, y, d + 1, board, word) ||
                     search(x, y + 1, d + 1, board, word) || search(x, y - 1, d + 1, board, word);
        board[y][x] = curr;
        return found;
    }
};
// @lc code=end
int main() {
    vector<vector<char>> board = {{'a', 'a', 'b', 'b'}, {'a', 'a', 'b', 'b'}};
    string word = "baa";
    Solution s;
    auto r = s.exist(board, word);

    return 0;
}