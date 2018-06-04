/**
 * 给定一个未排序的数组要求修改为满足如下条件：
 * nums[0] <= nums[1] >= nums[2] <= nums[3]....
 */

#include <vector>
using namespace std;

class Solution {
   public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return;
        for (int i = 1; i < n; i++) {
            /**
             * 交换存在两种情况：
             * 1. 在偶数位时，i比i-1大，由于i-1>=i-2前面是已经调整好的
             * 因此交换i与i-1后，i必然是更大于i-2的，不会捣乱前面的排序
             * 2. 在奇数位时，i比i-1小，由于i-1<=i-2前面同样已经调整好
             * 因此在交换i与i-2后，i必然是更小于i-2的
             */
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) ||
                (i % 2 == 0 && nums[i] > nums[i - 1]))
                swap(nums[i], nums[i - 1]);
        }
    }
};

int main() {
    Solution s = Solution();
    vector<int> testCase = {6, 4, 1, 2, 3};
    s.wiggleSort(testCase);
    return 0;
}