// #include "src/009PalindromeNumber.cpp"
#include <string>
#include "src/013RomanToInteger.cpp"

int main() {
    Solution test = Solution();
    int a = test.romanToInt("XXI");   // 21
    int b = test.romanToInt("XIV");   // 14
    int c = test.romanToInt("XCIX");  // 99
    return 0;
}