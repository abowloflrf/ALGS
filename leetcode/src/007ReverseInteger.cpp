#include <iostream>
class Solution {
   public:
    int reverse(int x) {
        char str[12] = {0};
        sprintf(str, "%d", x);

        bool isPositive = str[0] == '-' ? false : true;
        int index = isPositive ? 0 : 1;
        int p = 1;
        unsigned int result = 0;
        while (str[index] != '\0') {
            if (p == 1000000000) {
                //判断结果溢出
                if ((double)(str[index] - '0') * p > 0x7FFFFFFF - result) {
                    return 0;
                }
            }
            result += (int)(str[index] - '0') * p;
            index++;
            p *= 10;
        }
        return isPositive ? result : -result;
    }
    int reverse2(int x) {
        double res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return (res < INT_MIN || res > INT_MAX) ? 0 : (int)res;
    }
};