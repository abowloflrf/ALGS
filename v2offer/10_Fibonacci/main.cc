#include <iostream>
using namespace std;
//差劲的递归方法
long long badFibonacci(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return badFibonacci(n - 1) + badFibonacci(n - 2);
}
//优秀的循环方法
long long Fibonacci(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long fibOne = 1;
    long long fibTwo = 0;
    long long fibN = 0;
    for (unsigned int i = 2; i <= n; i++) {
        fibN = fibOne + fibTwo;
        fibTwo = fibOne;
        fibOne = fibN;
    }
    return fibN;
}

int main() {
    cout << Fibonacci(50) << endl;
    return 0;
}