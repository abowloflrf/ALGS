/**
 * 给定一个非负整数列表，向其中取数，不允许同时取相邻的两个数
 * 则从这个数组中最大可以取和为多少的数？
 * Challenge: time O(n) space O(1)
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    long long houseRobber(vector<int> &A) {
        if (A.size() == 0) return 0;
        long long dp0 = 0, dp1 = A[0], dp2 = A[0];
        for (int i = 2; i <= A.size(); ++i) {
            dp2 = max(dp1, dp0 + A[i - 1]);
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp2;
    }
};
int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<int> vec = {1, 3, 2, 1, 5};
    int sum = s.houseRobber(vec);
    return 0;
}
