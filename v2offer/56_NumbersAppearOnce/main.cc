//
// Created by ruofeng on 2018/7/25.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

//找到二进制的第一位1
int firstBit(int a) {
    int bitIndex = 0;
    while ((a & 1) == 0) {
        a >>= 1;
        bitIndex++;
    }
    return bitIndex;
}

//得到数字指定二进制位置的数（1或0）
int bitAtIndex(int num, int pos) {
    num >>= pos;
    return num & 1;
}

vector<int> findTwoNumber(vector<int> data) {
    int length = data.size();
    //首先全部异或一遍，得到的结果是独立的连个数异或的结果
    int resXOR = 0;
    for (int i = 0; i < length; ++i) {
        resXOR ^= data[i];
    }
    //然后将数据分为两组
    //根据异或结果的第一位1的位置，这两个数这个位置上的数一定是不一样的
    vector<int> leftVec, rightVec;
    int pos = firstBit(resXOR);
    for (auto i:data) {
        if (bitAtIndex(i, pos))
            leftVec.push_back(i);
        else
            rightVec.push_back(i);
    }
    int res1 = 0, res2 = 0;
    //分好后，两个数一定分别位于两个数组，再次循环异或即可得到结果
    for (auto i:leftVec)
        res1 ^= i;
    for (auto i:rightVec)
        res2 ^= i;
    return {res1, res2};
}

vector<int> findWithSet(vector<int> A) {
    unordered_set<int> S;
    for (auto i:A) {
        auto iter = S.find(i);
        if (iter == S.end())
            S.insert(i);
        else
            S.erase(i);
    }
    return vector<int>(S.begin(), S.end());
}

int main() {
    vector<int> data = {2, 41, 3, 23, 3, 2, 5, 5,};
    vector<int> res = findTwoNumber(data);
    return 0;
}
