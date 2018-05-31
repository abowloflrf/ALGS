/**
 * 一列数组要求重排，必须所有偶数位上的数都小于所有奇数位上的数
 * 同时，偶数位上的数也按照升序排序，奇数位上的也按照升序排序
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    //第一思路，先排序再交叉组成新数组
    vector<int> rearrange(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<int> result(size);
        int j = 0;
        for (int i = 0; i < size; i += 2) {
            result[i] = nums[j++];
        }
        for (int i = 1; i < size; i += 2) {
            result[i] = nums[j++];
        }
        return result;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vec = {-1, 0, 1, -1, 5, 10, 12};
    vector<int> res = s.rearrange(vec);
    return 0;
}