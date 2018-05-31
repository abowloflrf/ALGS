/**
 * 给一个转换规则来转换数字n：
 * n是奇数，n = 3n + 1
 * n是偶数，n = n / 2
 * 经过若干次转换后，n会变成1。
 * 现在给一个n，输出它转换到1需要的次数。
 */

#include <iostream>
using namespace std;
class Solution {
   public:
    int digitConvert(int n) {
        int count = 0;
        while (n != 1) {
            if (n % 2)
                n = 3 * n + 1;
            else
                n /= 2;
            count++;
        }
        return count;
    }
};

int main() {
    Solution s = Solution();
    int count = s.digitConvert(3);
    return 0;
}