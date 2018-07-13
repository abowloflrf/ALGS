#include <iostream>

using namespace std;

double absPower(double base, uint32_t exponent) {
    // double res = 1.0;
    // while (exponent) {
    //     res *= base;
    //     exponent--;
    // }
    //这里由于一直是乘的相同的数，因此指数为n时，可以以O(logn)的时间复杂度完成乘方
    if (exponent == 0) return 1;
    if (exponent == 1) return base;

    double result = absPower(base, exponent >> 1);
    result *= result;
    //判断奇偶
    if (exponent & 0x1 == 1) result *= base;
    return result;
}

double myPower(double base, int exponent) {
    //对于底数为0，指数为负数的情况，直接返回0
    if (base == 0.0 && exponent < 0) return 0.0;
    //对于指数为0，均返回1
    if (exponent == 0) return 1;

    //先计算指数为其绝对值的结果
    uint32_t absExponent = (uint32_t)(exponent);
    if (exponent < 0) absExponent = (uint32_t)(-exponent);
    double result = absPower(base, absExponent);

    //再根据指数是否是负数来将结果求倒数
    if (exponent < 0) {
        //计算结果的倒数
        result = 1 / result;
    }
    return result;
}

int main() {
    cout << absPower(2, 4) << endl;
    cout << myPower(2, -4) << endl;
    return 0;
}