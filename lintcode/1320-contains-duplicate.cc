/**
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 */
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> record = {};
        for (auto val : nums) {
            auto flag = record.insert(val);
            if (flag.second)
                continue;
            else
                return false;
        }
        return true;
    }
};

int main() {
    Solution s = Solution();
    vector<int> vec = {12, 34, 5,12, 7};
    bool res = s.containsDuplicate(vec);
    return 0;
}