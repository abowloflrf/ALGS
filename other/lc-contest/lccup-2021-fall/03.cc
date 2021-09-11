#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int flipChess(vector<string> &chessboard) {
        int maxFlipedCount = 0;
        for (int i = 0; i < chessboard.size(); i++) {
            for (int j = 0; j < chessboard.front().size(); j++) {
                // 当前位置四周有白棋则开始判断
                if ((i > 0 && chessboard[i - 1][j] == 'O') ||
                    (i < chessboard.size() - 1 && chessboard[i + 1][j] == 'O') ||
                    (j > 0 && chessboard[i][j - 1] == 'O') ||
                    (j < chessboard.front().size() - 1 && chessboard[i][j + 1] == 'O') ||
                    (i > 0 && j > 0 && chessboard[i - 1][j - 1] == 'O') ||
                    (i < chessboard.size() - 1 && j < chessboard.front().size() - 1 &&
                     chessboard[i + 1][j + 1] == 'O') ||
                    (i > 0 && j < chessboard.front().size() - 1 && chessboard[i - 1][j + 1] == 'O') ||
                    (i < chessboard.size() - 1 && j > 0 && chessboard[i + 1][j - 1] == 'O')) {
                    vector<string> c(chessboard);
                    c[i][j] = 'X';
                    maxFlipedCount = max(maxFlipedCount, countToFlip(c));
                }
            }
        }
        return maxFlipedCount;
    }
    int countToFlip(vector<string> &chessboard) {
        // 从第一个白棋开始判断
        int flipedCount = 0;
        for (int i = 0; i < chessboard.size(); i++) {
            for (int j = 0; j < chessboard.front().size(); j++) {
                if (chessboard[i][j] == 'O') {
                    /**
                    找到白棋，从4个方向判断能否反转
                    1. 左右
                    2. 上下
                    3. /
                    4. \
                     */

                    // 1
                    if (j > 0 && chessboard[i][j - 1] == 'X') {
                        // 左边有棋子且为黑
                        bool done = false;
                        int x = j;
                        while (x < chessboard.front().size()) {
                            if (chessboard[i][x] == 'X') {
                                done = true;
                                break;
                            }
                            if (chessboard[i][x] == '.')
                                break;
                            if (chessboard[i][x++] == 'O')
                                continue;
                        }
                        // 涂黑
                        if (done && x > j) {
                            for (int m = j; m < x; m++) {
                                chessboard[i][m] = 'X';
                                flipedCount++;
                            }
                        }
                    }
                    // 2
                    if (i > 0 && chessboard[i - 1][j] == 'X') {
                        // 上边有棋子且为黑
                        bool done = false;
                        int x = i;
                        while (x < chessboard.size()) {
                            if (chessboard[x][j] == 'X') {
                                done = true;
                                break;
                            }
                            if (chessboard[x][j] == '.')
                                break;
                            if (chessboard[x++][j] == 'O')
                                continue;
                        }
                        // 涂黑
                        if (done && x > i) {
                            for (int m = i; m < x; m++) {
                                chessboard[m][j] = 'X';
                                flipedCount++;
                            }
                        }
                    }
                    // 3
                    if (i > 0 && j > 0 && chessboard[i - 1][j - 1] == 'X') {
                        // 左上边有棋子且为黑
                        bool done = false;
                        int x = i, y = j;
                        while (x < chessboard.size() && y < chessboard.front().size()) {
                            if (chessboard[x][y] == 'X') {
                                done = true;
                                break;
                            }
                            if (chessboard[x][y] == '.')
                                break;
                            if (chessboard[x++][y++] == 'O')
                                continue;
                        }
                        // 涂黑
                        if (done && x > i) {
                            for (int m = i, n = j; m < x && n < y; m++, n++) {
                                chessboard[m][n] = 'X';
                                flipedCount++;
                            }
                        }
                    }
                    // 4
                    if (i > 0 && j < chessboard.front().size() - 1 && chessboard[i - 1][j + 1] == 'X') {
                        // 右上边有棋子且为黑
                        bool done = false;
                        int x = i, y = j;
                        while (x < chessboard.size() && y >= 0) {
                            if (chessboard[x][y] == 'X') {
                                done = true;
                                break;
                            }
                            if (chessboard[x][y] == '.')
                                break;
                            if (chessboard[x++][y--] == 'O')
                                continue;
                        }
                        // 涂黑
                        if (done && x > i) {
                            for (int m = i, n = j; m < x && n > y; m++, n--) {
                                chessboard[m][n] = 'X';
                                flipedCount++;
                            }
                        }
                    }
                    // 四个方向找完之后，有找到变色的
                    if (flipedCount > 0) {
                        return countToFlip(chessboard) + flipedCount;
                    }
                }
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[]) {

    Solution s;
    vector<string> chessboard = {"....X.", "....O.", "XOOO..", "......", "......"};
    int ans = s.flipChess(chessboard);
    return 0;
}
