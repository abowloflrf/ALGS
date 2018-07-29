//
// Created by ruofeng on 2018/7/29.
//
// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
//
// The solution set must not contain duplicate triplets.
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.size() < 3)
            return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int n1 = nums[i];
            int targetSum = -n1;
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < targetSum)
                    front++;
                else if (sum > targetSum)
                    back--;
                else {
                    int n2 = nums[front];
                    int n3 = nums[back];
                    res.push_back({n1, nums[front], nums[back]});
                    //消除重复的n2 n3
                    while (front < back && nums[front] == n2) front++;
                    while (front < back && nums[back] == n2) back--;
                }
            }
            //消除重复的n1
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = s.threeSum(nums);
    for (auto i:res) {
        for (auto j:i)
            cout << j << "|";
        cout << endl;
    }
    return 0;
}