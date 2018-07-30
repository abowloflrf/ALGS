//
// Created by ruofeng on 2018/7/30.
//

#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        //从左右两边开始搜索到中间只间隔一个数
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            //若左数小于中间的数，说明0位置靠左
            if (nums[left] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        if (target == nums[left]) return left;
        if (target == nums[right]) return right;
        return -1;
    }
};