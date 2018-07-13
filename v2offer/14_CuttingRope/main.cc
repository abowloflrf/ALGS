#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getMax(int length) {
    if (length < 2) return 0;
    if (length == 2) return 1;
    if (length == 3) return 2;

    vector<int> results(length + 1);
    results[0] = 0;
    results[1] = 1;  //第二个元素，长度为2是，剪成1*1，结果为1
    results[2] = 2;
    results[3] = 3;

    int maxResult = 0;

    for (int i = 4; i <= length; i++) {
        maxResult = 0;
        // i-1长度以下的结果都已经得到，当前计算长度为i绳子能得到的最大值
        //对于i长度的绳子，即将i分成两个部分相乘如[1]*[i-1]一直计算到[i/2]*[i/2]
        //保存最大值
        for (int j = 1; j <= i / 2; j++) {
            int result = results[j] * results[i - j];
            if (maxResult < result) maxResult = result;
            results[i] = maxResult;
        }
    }
    return results[length];
}

int main(int argc, char const *argv[]) {
    if (argc > 1) {
        cout << getMax(stoi(argv[1])) << endl;
    }
    return 0;
}