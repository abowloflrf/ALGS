//
// Created by ruofeng on 2018/8/1.
//
// You are given an n x n 2D matrix representing an image.
//
// Rotate the image by 90 degrees (clockwise).

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        //i=0表示最外层
        for (int i = 0; i < n / 2; i++) {
            //交换某层的第j个数，一个循环种交换四个边的数
            for (int j = 0; j < n - i * 2 - 1; j++) {
                int tmp = matrix[i][j + i];
                matrix[i][j + i] = matrix[n - 1 - i - j][i];
                swap(tmp, matrix[j + i][n - 1 - i]);
                swap(tmp, matrix[n - 1 - i][n - 1 - i - j]);
                swap(tmp, matrix[n - 1 - i - j][i]);
            }
        }
    }
};

int main() {
    vector<vector<int>> m1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    vector<vector<int>> m2 = {
        {1, 2, 3},
        {5, 6, 7},
        {9, 10, 11}
    };
    Solution s;
    s.rotate(m2);
    for (auto a:m2) {
        for (auto b:a)
            cout << b << "-";
        cout << endl;
    }
    return 0;
}