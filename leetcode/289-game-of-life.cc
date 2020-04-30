/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (48.78%)
 * Likes:    1580
 * Dislikes: 262
 * Total Accepted:    167.5K
 * Total Submissions: 318.6K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 *
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 *
 *
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 *
 *
 * Write a function to compute the next state (after one update) of the board
 * given its current state. The next state is created by applying the above
 * rules simultaneously to every cell in the current state, where births and
 * deaths occur simultaneously.
 *
 * Example:
 *
 *
 * Input:
 * [
 * [0,1,0],
 * [0,0,1],
 * [1,1,1],
 * [0,0,0]
 * ]
 * Output:
 * [
 * [0,0,0],
 * [1,0,1],
 * [0,1,1],
 * [0,1,0]
 * ]
 *
 *
 * Follow up:
 *
 *
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
/**
 * 0,1 活->死
 * 2,3 活->活
 * 4+  活->死
 * 3   死->活
 **/
class Solution {
  public:
    void gameOfLife(vector<vector<int>> &board) {
        vector<vector<int>> newBoard = vector<vector<int>>(board.size(), vector<int>(board.back().size(), 0));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board.back().size(); j++) {
                int ra = roundAlive(i, j, board);
                if (board[i][j] == 0 && ra == 3)
                    newBoard[i][j] = 1;
                else if (board[i][j] == 1 && (ra == 2 || ra == 3))
                    newBoard[i][j] = 1;
                else
                    newBoard[i][j] = 0;
            }
        board = newBoard;
    }

  private:
    int roundAlive(int i, int j, vector<vector<int>> &board) {
        int cnt = 0;
        int height = board.size();
        int width = board.back().size();
        if (i >= 1 && board[i - 1][j] == 1)
            cnt++;
        if (i <= height - 2 && board[i + 1][j] == 1)
            cnt++;
        if (j >= 1 && board[i][j - 1] == 1)
            cnt++;
        if (j <= width - 2 && board[i][j + 1] == 1)
            cnt++;
        if (i <= height - 2 && j <= width - 2 && board[i + 1][j + 1] == 1)
            cnt++;
        if (i >= 1 && j >= 1 && board[i - 1][j - 1] == 1)
            cnt++;
        if (i <= height - 2 && j >= 1 && board[i + 1][j - 1] == 1)
            cnt++;
        if (i >= 1 && j <= width - 2 && board[i - 1][j + 1] == 1)
            cnt++;
        return cnt;
    }
};
// @lc code=end
