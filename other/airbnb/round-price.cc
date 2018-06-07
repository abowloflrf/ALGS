#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class DiffNum {
   public:
    int index;
    float diff;
    DiffNum(int i, float d) {
        index = i;
        diff = d;
    }
    bool operator<(const DiffNum &b) { return diff < b.diff; }
};

vector<int> getIntList(vector<float> fList) {
    int sum = 0;       //目标和
    int floorSum = 0;  //全部floor后的和
    float tempFloat = 0;
    vector<DiffNum> vecDiff;
    vector<int> res;
    for (int i = 0; i < fList.size(); i++) {
        int floorNum = floor(fList[i]);
        res.push_back(floorNum);
        tempFloat += fList[i];
        floorSum += floorNum;
        //将 价格的index 和 floor后的数与原数之差 保存下来后面排序
        vecDiff.push_back(DiffNum(i, (float)(fList[i] - floorNum)));
    };
    sum = round(tempFloat);  //期望的正确整数和

    //与期望和之差
    int offset = sum - floorSum;
    //将所有价格floor后与原浮点数之差倒序排列
    sort(vecDiff.rbegin(), vecDiff.rend());
    //按照floor差从大到小的顺序，每将一个变成ceil则offset能减一
    //因此按顺序ceil offset个价格
    for (int i = 0; i < offset; i++) {
        int index = vecDiff[i].index;
        if (res[index] - ceil(fList[index]) == 0)  //针对本来就是整数的价格
            res[index]++;
        else
            res[index] = ceil(fList[index]);
    }
    return res;
};

int main() {
    vector<float> fList = {1.2, 3.7, 2.3, 4.8, 5.0};
    vector<int> res = getIntList(fList);
    return 0;
}