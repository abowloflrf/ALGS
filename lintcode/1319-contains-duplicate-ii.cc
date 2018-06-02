/**
 * Given an array of integers and an integer k
 * find out whether there are two distinct indices i and j in the array such
 * that nums[i] = nums[j] and the absolute difference between i and j is at most
 * k.
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * @param nums: the given array
     * @param k: the given number
     * @return:  whether there are two distinct indices i and j in the array
     * such that nums[i] = nums[j] and the absolute difference between i and j
     * is at most k
     */
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            //找到则计算距离之差，小于k则返回true
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k)
                return true;
            else
                //未找到则插入
                m[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vec = {1, 2, 3, 4, 5};
    int res = s.containsNearbyDuplicate(vec, 5);
    return 0;
}