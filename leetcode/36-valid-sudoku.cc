/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (45.24%)
 * Likes:    1327
 * Dislikes: 423
 * Total Accepted:    321.3K
 * Total Submissions: 684K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 *
 *
 *
 * A partially filled sudoku which is valid.
 *
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 *
 *
 * Note:
 *
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        // 小九宫格
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                bool r[9] = {false};
                for (int l = 0; l < 3; l++) {
                    for (int m = 0; m < 3; m++) {
                        char n = board[i * 3 + l][j * 3 + m];
                        if (n == '.')
                            continue;
                        if (r[n - '1'])
                            return false;
                        r[n - '1'] = true;
                    }
                }
            }
        }
        // 横行9行
        for (int i = 0; i < 9; i++) {
            bool r[9] = {false};
            for (int j = 0; j < 9; j++) {
                char n = board[i][j];
                if (n == '.')
                    continue;
                if (r[n - '1'])
                    return false;
                r[n - '1'] = true;
            }
        }
        // 纵向9列
        for (int i = 0; i < 9; i++) {
            bool r[9] = {false};
            for (int j = 0; j < 9; j++) {
                char n = board[j][i];
                if (n == '.')
                    continue;
                if (r[n - '1'])
                    return false;
                r[n - '1'] = true;
            }
        }
        return true;
    }
};
// @lc code=end
