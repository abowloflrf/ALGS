#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> singleNumbers(vector<int> &nums) {
        // 逐个异或
        int t = 0;
        for (int n : nums) {
            t ^= n;
        }
        // 得到的 t 为目标两个数的异或
        // 找到首位非 0 的二进制位置
        int bitPosition = 1;
        while ((t & 1) == 0) {
            t >>= 1;
            bitPosition <<= 1;
        }

        int a = 0, b = 0;
        for (int n : nums) {
            // 根据二进制位数上的差异，分别异或
            if ((n & bitPosition) == 0) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        return {a, b};
    }
};