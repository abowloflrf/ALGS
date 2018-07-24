//
// Created by ruofeng on 2018/7/24.
//

#include <iostream>
#include <string>

using namespace std;

int getR(string num) {
    int len = num.length();
    if (len < 2)
        return 1;
    if ((10 * (num[0] - '0') + num[1] - '0') < 26) {
        //前两位在00-25，即说明可以选择转换两位或者一位
        return getR(num.substr(2)) + getR(num.substr(1));
    } else {
        return getR(num.substr(1));
    }

}

int getNumberOfTranslation(int number) {
    //先将数字转换为字符串
    char num[100];
    sprintf(num, "%d", number);
    string str = num;
    return getR(str);
}

int main() {
    int data = 12258;
    int res = getNumberOfTranslation(data);
    cout << res << endl;
    return 0;
}
