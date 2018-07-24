//
// Created by ruofeng on 2018/7/24.
//
#include <vector>
#include <iostream>
using namespace std;

int nthUglyNumber(int n) {
    //记录第一个数
    vector<int> res = {1};
    //i保存的是当前数组中能够使得i*2大于当前结果数组中最大值的最小下标，jk同理，分别是 *3 *5
    int i = 0, j = 0, k = 0;
    while (res.size() != n) {
        res.push_back(min(res[i] * 2, min(res[j] * 3, res[k] * 5)));//将ijk所指位置最小的一个元素加入到末尾
        if (res.back() == res[i] * 2) i++;
        if (res.back() == res[j] * 3) j++;
        if (res.back() == res[k] * 5) k++;
    }
    return res[n - 1];
}

int main(int argc, const char **argv) {
    if (argc > 1)
        cout << nthUglyNumber(atoi(argv[1])) << endl;
    return 0;
}