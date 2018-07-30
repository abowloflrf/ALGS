//
// Created by ruofeng on 2018/7/30.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        int length = nums.size();
        if (target < nums[0])
            return 0;
        if (target > nums[length - 1])
            return length;
        int index = search(nums, target, 0, length - 1);
        if (nums[index] < target)
            index++;
        return index;

    }
  private:
    //二分搜索目标数，若没有则找到最接近的小于目标数的位置
    int search(vector<int> &nums, int target, int left, int right) {
        if (right <= left)
            return left;
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
    vector<int> numbers = {1, 3, 5, 6};
    Solution s;
    int index = s.searchInsert(numbers, 2);
    cout << index << endl;
    return 0;
}