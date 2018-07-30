//
// Created by ruofeng on 2018/7/30.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int length = nums.size();
        //先使用二分找到目标数的位置
        int index = search(nums, target, 0, length - 1);
        //未找到则直接返回-1
        if (index == -1)
            return {-1, -1};
        //再在目标数的两边找相同的数
        int left = index, right = index;
        while (left > 0 && nums[left - 1] == target) left--;
        while (right < length - 1 && nums[right + 1] == target)right++;
        return {left, right};
    }
  private:
    //二分搜索
    int search(vector<int> &nums, int target, int left, int right) {
        if (right < left || nums[left] > target || nums[right] < target)
            return -1;
        int middleIndex = left + (right - left) / 2;
        if (nums[middleIndex] > target)
            return search(nums, target, left, middleIndex - 1);
        else if (nums[middleIndex] < target)
            return search(nums, target, middleIndex + 1, right);
        else
            return middleIndex;
    }

};

int main() {
    vector<int> numbers = {1, 1, 2};
    Solution s;
    vector<int> res = s.searchRange(numbers, 1);
    cout << res[0] << endl;
    cout << res[1] << endl;
    return 0;
}