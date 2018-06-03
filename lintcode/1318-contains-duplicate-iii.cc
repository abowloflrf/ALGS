/**
 * Given an array of integers and an integer k
 * find out whether there are two distinct indices i and j in the array such
 * that nums[i] = nums[j] and the absolute difference between i and j is at most
 * k.
 */

#include <iostream>
#include <map>
#include <set>
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
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        map<int, int> m;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i - start > k) m.erase(nums[start++]);
            map<int, int>::iterator it = m.lower_bound(nums[i] - t);
            if (it != m.end() && abs(it->first - nums[i]) <= t) return true;
            // map<int, int>::iterator it = m.begin();
            // while (it != m.end()) {
            //     if (abs(it->second - nums[i]) <= t) return true;
            //     it++;
            // }
            m[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vec = {10, 20, 30, 40, 50, 60, 70, 80, 90, 40, 100, 110};
    bool res = s.containsNearbyAlmostDuplicate(vec, 4, 4);
    return 0;
}