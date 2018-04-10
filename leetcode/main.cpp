#include <string>
#include <vector>
#include "src/014LongestCommonPrefix.cpp"
using namespace std;
int main() {
    Solution test = Solution();
    vector<string> vec = {"abcdef", "abcgh", "abcdefghj", "abcdfq", "abcdexy"};
    string longestCommonStr = test.longestCommonPrefix(vec);
    cout << longestCommonStr << endl;
    return 0;
}