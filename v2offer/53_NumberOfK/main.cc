//
// Created by ruofeng on 2018/7/24.
//

#include <vector>
#include <iostream>

using namespace std;

int findTarget(vector<int> data, int start, int end, int target) {
    if (start > end)
        return -1;
    int middle = start + (end - start) / 2;
    if (data[middle] == target)
        return middle;
    if (data[middle] > target)
        return findTarget(data, start, middle - 1, target);
    else
        return findTarget(data, middle + 1, end, target);
}

int getNumberK(vector<int> data, int target) {
    //首先找到目标数
    int index = findTarget(data, 0, data.size() - 1, target);
    if (index == -1)
        return 0;
    //向左右寻找相等的数
    int cnt = 1;
    int left = index - 1, right = index + 1;
    while (left >= 0 && data[left] == target) {
        cnt++;
        left--;
    }
    while (right < data.size() && data[right] == target) {
        cnt++;
        right++;
    }
    return cnt;
}

int main() {
    vector<int> data = {1, 4, 5, 6, 9, 10, 13, 13, 13, 15, 15, 15, 15, 15, 20, 23, 23, 34};
    cout << getNumberK(data, 23) << endl;
    return 0;
}