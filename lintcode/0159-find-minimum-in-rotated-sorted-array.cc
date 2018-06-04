#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        if (nums.empty()) return -1;

        int left = 0;
        int right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            // mid<left说明左边全部递减，最小值在右边
            if (nums[mid] <= nums[right]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return min(nums[left], nums[right]);
    }
};

int main() {
    Solution s = Solution();
    vector<int> test = {7, 8, 9, 10, 0, 1, 2, 3, 5, 6};
    int m = s.findMin(test);
    return m;
}