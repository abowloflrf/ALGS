#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int movingCount() {
        if (threshold < 0 || rows <= 0 || cols <= 0) return 0;
        return movingCountCore(0, 0);
    }
    Solution(int threshold, int rows, int cols) {
        this->threshold = threshold;
        this->cols = cols;
        this->rows = rows;
        this->visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
    }

   private:
    int threshold;
    int rows;
    int cols;
    vector<vector<bool>> visited;
    int movingCountCore(int row, int col) {
        int count = 0;
        //当前点可以到达
        if (check(row, col)) {
            visited[row][col] = true;
            count = 1 + movingCountCore(row - 1, col) +
                    movingCountCore(row, col - 1) +
                    movingCountCore(row + 1, col) +
                    movingCountCore(row, col + 1);
        }
        //当前点不可到达则直接返回0
        return count;
    }
    bool check(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols)
            if (getDigitalSum(row) + getDigitalSum(col) <= threshold &&
                !visited[row][col])
                return true;
        return false;
    }
    int getDigitalSum(int number) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
};

int main() {
    Solution s(21, 40, 50);
    cout << s.movingCount() << endl;
    return 0;
}