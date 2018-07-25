//
// Created by ruofeng on 2018/7/25.
//
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
        m[nums[i]] = i;
    for (int i = 0; i < nums.size(); i++) {
        auto iter = m.find(target - nums[i]);
        if (iter != m.end() && iter->second > i)
            return {i, iter->second};
    }
}