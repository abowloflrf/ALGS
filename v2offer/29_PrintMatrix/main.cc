#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        // initial data
        m=matrix;
        height = matrix.size();
        if(height==0)
            return result;
        width = matrix[0].size();
        if(width==0)
            return result;
        start = 0;
        while (width > start * 2 && height > start * 2) {
            printR();
            start++;
        }
        return result;
    }

   private:
   vector<vector<int>> m;
    int width;
    int height;
    int start;
    vector<int> result;
    void printR() {
        int indexX = start;
        int indexY = start;
        //只剩最里面一纵行
        if (2 * start == width - 1) {
            int num = height - 2 * start;
            for (int i = 0; i < num; i++) result.push_back(m[indexY++][start]);
            return;
        }
        //只剩最里面一横列
        if (2 * start == height - 1) {
            int num = width - 2 * start;
            for (int i = 0; i < num; i++) result.push_back(m[start][indexX++]);
            return;
        }

        //上
        for (; indexX < width - start - 1; indexX++)
            result.push_back(m[indexY][indexX]);
        //右
        for (; indexY < height - start - 1; indexY++)
            result.push_back(m[indexY][indexX]);
        //下
        for (; indexX > start; indexX--) result.push_back(m[indexY][indexX]);
        //左
        for (; indexY > start; indexY--) result.push_back(m[indexY][indexX]);
    }
};


int main() {
    vector<vector<int>> matrix = {
        {1},
        {9},
        {5}
    };
    Solution s;
    vector<int> result=s.printMatrix(matrix);
    for(auto i : result)
        cout<<i<<"-";
    return 0;
}