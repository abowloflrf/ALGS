#include <iostream>
#include <string>
using namespace std;

//判断无符号整数（不能有符号）
bool isUnsignedInteger(string& str) {
    int len = str.length();
    int index = 0;
    int result = false;
    while (index < len && str[index] >= '0' && str[index] <= '9') index++;
    str = str.substr(index);
    return index > 0;
}

//判断整数（有无符号均可）
bool isInteger(string& str) {
    if (str[0] == '+' || str[0] == '-') str = str.substr(1);
    return isUnsignedInteger(str);
};

bool isNumeric(string& str) {
    if (str.empty()) return false;
    
    bool result = isInteger(str);  //先截取前面的数字

    //若出现小数点
    if (str[0] == '.') {
        str = str.substr(1);
        //截取小数点后的无符号数字，有小数点时，前面整数部分可以是空，因此或一下前面的结果
        //这里result为false的情况即开头第一个字符就是小数点
        result = isUnsignedInteger(str) || result;
    }

    //若出现指数形式
    if (str[0] == 'e' || str[0] == 'E') {
        str = str.substr(1);
        result = isInteger(str) && result;
    }

    return result && str.empty();
}

int main(int argc, char const* argv[]) {
    string str = argv[1];
    cout << isNumeric(str) << endl;
    return 0;
}
