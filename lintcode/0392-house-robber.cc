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
        int n = A.size();
        if (n == 0) return 0;
        if (n == 1) return A[0];

        //在循环中同时保存取前面m个、m-1个时的最大值
        //然后f保存 取当前数+m-1的值、取前m个的 两个中的最大值
        //然后更新f1,f2
        long long f1 = A[0], f2 = max(A[0], A[1]);
        for (int i = 2; i < A.size(); ++i) {
            long long f = max(f1 + A[i], f2);
            f1 = f2;
            f2 = f;
        }
        return f2;
    }
};
int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<int> vec = {1, 3, 2, 1, 5};
    long long sum = s.houseRobber(vec);
    return 0;
}
