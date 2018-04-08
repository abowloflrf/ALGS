// #include "src/009PalindromeNumber.cpp"
#include "src/007ReverseInteger.cpp"

int main() {
    Solution test = Solution();
    // bool a = test.isPalindrome(123);
    // bool c = test.isPalindrome(123321);
    // bool d = test.isPalindrome(12321);
    // bool e = test.isPalindrome(-123321);
    // bool f = test.isPalindrome(1147483648);
    // bool g = test.isPalindrome(1234554321);
    int a = test.reverse(123);
    int b = test.reverse(120);
    int c = test.reverse(-333);
    int d = test.reverse(-550);
    int e = test.reverse(-2147483412);
    int f = test.reverse(1534236469);
    return 0;
}