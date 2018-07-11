#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<char>> matrix;
    vector<vector<bool>> visited;
    int rows;
    int cols;
    int pathLength;
    bool hasPathCore(int row, int col, string str) {
        //寻找目标字符串的所有字符
        if (str.length() == pathLength) {
            return true;
        }
        bool result = false;
        if (row >= 0 && row < rows && col >= 0 && col < cols &&
            matrix[row][col] == str[pathLength] && !visited[row][col]) {
            pathLength++;
            visited[row][col] = true;
            //在四个方向寻找下一个目标字符
            result = hasPathCore(row, col - 1, str) ||
                     hasPathCore(row - 1, col, str) ||
                     hasPathCore(row, col + 1, str) ||
                     hasPathCore(row + 1, col, str);
            //下一个方向未找到，则回溯
            if (!result) {
                pathLength--;
                visited[row][col] = false;
            }
        }
        return result;
    }

   public:
    Solution(vector<vector<char>> m) {
        matrix = m;
        rows = matrix.size();
        cols = matrix[0].size();
        pathLength = 0;
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
    }
    bool hasPath(string str) {
        for (int row = 0; row < rows; row++)
            for (int col = 0; col < cols; col++)
                if (hasPathCore(row, col, str)) return true;
        return false;
    }
};

int main() {
    vector<vector<char>> matrix = {
        {'a', 'b', 't', 'g'}, {'c', 'f', 'c', 's'}, {'j', 'd', 'e', 'h'}};
    Solution s(matrix);
    string target = "bfce";
    bool res = s.hasPath(target);
    cout << res << endl;
    return 0;
}