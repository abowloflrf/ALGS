#include <iostream>
#include <string>

using namespace std;

bool increment(string &numberStr) {
    bool isOverflow = false;
    int len = numberStr.length();
    int carry = 0;
    for (int i = len - 1; i >= 0; i--) {
        //累加该位
        int nSum = numberStr[i] - '0' + carry;
        //加一
        if (i == len - 1) nSum++;
        //处理进位
        if (nSum >= 10) {
            if (i == 0)
                // i==0已经到n位长度
                isOverflow = true;
            else {
                //还没有到头则处理进位
                //此位数字减10
                //设置进位标志为1
                nSum -= 10;
                carry = 1;
                numberStr[i] = char('0' + nSum);
            }
        } else {
            //没有进位，则直接将这一位数字赋值
            char target = '0' + nSum;
            numberStr[i] = target;
            break;
        }
    }
    return isOverflow;
}

void printNumber(string numberStr) {
    int len = numberStr.length();
    bool start = false;
    for (int i = 0; i < len; i++) {
        if (!start && numberStr[i] == '0')
            continue;
        else
            start = true;
        cout << numberStr[i];
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    if (argc > 1) {
        int n = atoi(argv[1]);
        if (n <= 0) return 0;
        string number(n, '0');
        while (!increment(number)) {
            printNumber(number);
        }
    }
    return 0;
}
