#include <cmath>
#include <iostream>
class Solution {
   public:
    int reverse(int x) {
        bool isPositive = x < 0 ? false : true;
        //将整型数据转为字符串储存
        char str[11] = {0};
        sprintf(str, "%d", abs(x));

        int index = 0;
        //定义64位的int避免加法时溢出
        long long result = 0;
        while (str[index] != '\0') {
            result += (int)(str[index] - '0') * pow(10, index);
            index++;
        }
        //结果溢出返回0
        if (result > INT32_MAX) return 0;
        return isPositive ? (int)result : (int)-result;
    }

    //代码更加精简的写法
    int reverse2(int x) {
        long long result = 0;
        while (x) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return (result < INT32_MIN || result > INT32_MAX) ? 0 : (int)result;
    }
};