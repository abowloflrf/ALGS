#include <iostream>
#include <string>
#include <vector>
#include "./src/007ReverseInteger.cpp"

int main() {
    Solution test = Solution();
    int a = test.reverse(123);
    int b = test.reverse(120);
    int c = test.reverse(-333);
    int d = test.reverse(-550);
    int e = test.reverse(-2147483412);
    int f = test.reverse(1534236469);
    return 0;
}