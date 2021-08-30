#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  public:
    int minimumDifference(vector<int> &nums, int k) {
        if (k == 1)
            return 0;
        if (k > nums.size())
            return -1;
        // 先排序
        sort(nums.begin(), nums.end());
        // 再窗口
        int minDiff = 100001;
        for (int i = 0; i <= nums.size() - k; i++) {
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
        }
        return minDiff;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> nums = {9, 4, 1, 7};
    int ans = s.minimumDifference(nums, 2);
    return 0;
}
