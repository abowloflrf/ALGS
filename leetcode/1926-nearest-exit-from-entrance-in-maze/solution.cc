/*
 * @lc app=leetcode.cn id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 *
 * https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/description/
 *
 * algorithms
 * Medium (39.86%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    18.5K
 * Total Submissions: 46.5K
 * Testcase Example:  '[["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]\n[1,2]'
 *
 * You are given an m x n matrix maze (0-indexed) with empty cells (represented
 * as '.') and walls (represented as '+'). You are also given the entrance of
 * the maze, where entrance = [entrancerow, entrancecol] denotes the row and
 * column of the cell you are initially standing at.
 *
 * In one step, you can move one cell up, down, left, or right. You cannot step
 * into a cell with a wall, and you cannot step outside the maze. Your goal is
 * to find the nearest exit from the entrance. An exit is defined as an empty
 * cell that is at the border of the maze. The entrance does not count as an
 * exit.
 *
 * Return the number of steps in the shortest path from the entrance to the
 * nearest exit, or -1 if no such path exists.
 *
 *
 * Example 1:
 *
 *
 * Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]],
 * entrance = [1,2]
 * Output: 1
 * Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
 * Initially, you are at the entrance cell [1,2].
 * - You can reach [1,0] by moving 2 steps left.
 * - You can reach [0,2] by moving 1 step up.
 * It is impossible to reach [2,3] from the entrance.
 * Thus, the nearest exit is [0,2], which is 1 step away.
 *
 *
 * Example 2:
 *
 *
 * Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
 * Output: 2
 * Explanation: There is 1 exit in this maze at [1,2].
 * [1,0] does not count as an exit since it is the entrance cell.
 * Initially, you are at the entrance cell [1,0].
 * - You can reach [1,2] by moving 2 steps right.
 * Thus, the nearest exit is [1,2], which is 2 steps away.
 *
 *
 * Example 3:
 *
 *
 * Input: maze = [[".","+"]], entrance = [0,0]
 * Output: -1
 * Explanation: There are no exits in this maze.
 *
 *
 *
 * Constraints:
 *
 *
 * maze.length == m
 * maze[i].length == n
 * 1 <= m, n <= 100
 * maze[i][j] is either '.' or '+'.
 * entrance.length == 2
 * 0 <= entrancerow < m
 * 0 <= entrancecol < n
 * entrance will always be an empty cell.
 *
 *
 */
#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    // 需要 bfs 不能 dfs
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        int step = 0;
        queue<pair<int, int>> path;
        path.push(make_pair(entrance[0], entrance[1]));
        cout << maze.size() << "," << maze[0].size() << endl;
        while (!path.empty()) {
            int size = path.size();
            cout << size << endl;
            for (int i = 0; i < size; i++) {
                auto p = path.front();
                path.pop();

                maze[p.first][p.second] = '+';
                if (p.first == 0 || p.second == 0 || p.first == maze.size() - 1 || p.second == maze[0].size() - 1) {
                    if (step != 0)
                        return step;
                }

                // 注意剪枝，走过地方置为墙，不走回头路
                // 上 x-1
                if ((p.first - 1 >= 0) && maze[p.first - 1][p.second] != '+') {
                    maze[p.first - 1][p.second] = '+';
                    path.push(make_pair(p.first - 1, p.second));
                }
                // 下 x+1
                if ((p.first + 1 < maze.size()) && maze[p.first + 1][p.second] != '+') {
                    maze[p.first + 1][p.second] = '+';
                    path.push(make_pair(p.first + 1, p.second));
                }
                // 左
                if ((p.second - 1 >= 0) && maze[p.first][p.second - 1] != '+') {
                    maze[p.first][p.second - 1] = '+';
                    path.push(make_pair(p.first, p.second - 1));
                }
                // 右
                if ((p.second + 1 < maze[0].size()) && maze[p.first][p.second + 1] != '+') {
                    maze[p.first][p.second + 1] = '+';
                    path.push(make_pair(p.first, p.second + 1));
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end
