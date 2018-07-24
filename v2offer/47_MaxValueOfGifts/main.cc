//
// Created by ruofeng on 2018/7/24.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int getMaxValue(vector<vector<int>> map) {
    int width = map[0].size();
    int height = map.size();
    int dp[height][width];

    //dp[i][j]表示从左上角走到[i][j]位置能得到的最大值
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            int up = 0;
            int left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            //从上面过来或从左边过来的最大值，加上当前格子的数值
            dp[i][j] = max(up, left) + map[i][j];
        }
    return dp[height - 1][width - 1];
}

int main() {
//    vector<vector<int>> map = {
//        {1, 10, 3, 8},
//        {12, 2, 9, 6},
//        {5, 7, 4, 11},
//        {3, 7, 16, 5}
//    };
    vector<vector<int>> map = {
        {1, 2, 5},
        {3, 2, 1}
    };

    int res = getMaxValue(map);
    cout << res << endl;
    return 0;
}
