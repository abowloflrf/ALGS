/**
 * 以字符串的形式给出两个非负整数 num1 和 num2，返回 num1 和 num2 的和。
 * num1 和 num2 的长度都小于5100。
 * num1 和 num2 都只包含数字 0-9。
 * num1 和 num2 都不包含任何前导零。
 * 您不能使用任何内置的BigInteger库内的方法或直接将输入转换为整数。
 */

#include <iostream>
#include <string>
using namespace std;

string addStrings(string &num1, string &num2) {
    string ret = "";
    int len1 = num1.length();
    int len2 = num2.length();
    int carry = 0;
    int n1 = len1 - 1, n2 = len2 - 1;
    while (n1 >= 0 || n2 >= 0) {
        int sum = carry;
        sum += (n1 >= 0) ? num1[n1--] - '0' : 0;
        sum += (n2 >= 0) ? num2[n2--] - '0' : 0;
        carry = sum / 10;
        sum %= 10;
        ret = (char)(sum + '0') + ret;
    }
    if (carry) ret = '1' + ret;
    return ret;
}

int main(int argc, char const *argv[]) {
    string n1 = "6";
    string n2 = "49";
    string res = addStrings(n1, n2);
    cout << res << endl;
    return 0;
}
