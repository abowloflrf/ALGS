//
// Created by ruofeng on 2018/7/25.
//

#include <vector>
#include <iostream>

using namespace std;

int getMaxProfit(vector<int> data) {
    int min = data[0];
    int maxProfit = data[1] - min;
    int length = data.size();
    for (int i = 2; i < length; ++i) {
        //保存i位置前面最小值
        if (data[i - 1] < min)
            min = data[i - 1];
        //计算买入i时与前面最小值之差
        int curr = data[i] - min;
        if (curr > maxProfit)
            maxProfit = curr;
    }
    return maxProfit;
}

int main() {
    vector<int> data = {199, 200, 11, 8, 5, 7, 12, 16, 14};
    cout << getMaxProfit(data) << endl;
    return 0;
}