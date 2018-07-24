//
// Created by ruofeng on 2018/7/24.
//
#include <iostream>
#include <cmath>

using namespace std;

int getDigit(int n) {
    int width = 1;
    long long base = 9;
    while (n - base * width > 0) {
        n -= base * width;
        base *= 10;
        width++;
    }

    long long targetNumber;
    int index;
    if (n % width == 0) {
        targetNumber = (int) pow(10, width - 1) + n / width - 1;
        index = width;
    } else {
        targetNumber = (int) pow(10, width - 1) + n / width;
        index = n % width;
    }

    for (int i = index; i < width; i++) {
        targetNumber /= 10;
    }
    return (int) targetNumber % 10;

}

int main(int argc, const char **argv) {
    if (argc > 1) {
        int n = atoi(argv[1]);
        cout << getDigit(n) << endl;
    } else {
        cout << getDigit(1000000000) << endl;
    }

    return 0;
}
