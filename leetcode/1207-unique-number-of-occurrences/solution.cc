/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 *
 * https://leetcode.cn/problems/unique-number-of-occurrences/description/
 *
 * algorithms
 * Easy (73.19%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    95.9K
 * Total Submissions: 131K
 * Testcase Example:  '[1,2,2,1,1,3]'
 *
 * Given an array of integers arr, return true if the number of occurrences of
 * each value in the array is unique or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [1,2,2,1,1,3]
 * Output: true
 * Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two
 * values have the same number of occurrences.
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 1000
 * -1000 <= arr[i] <= 1000
 *
 *
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_set<int> s;
        unordered_map<int, int> m;
        for (const auto& i : arr) {
            m[i]++;
        }
        for (const auto& i : m) {
            if (s.find(i.second) == s.end()) {
                s.insert(i.second);
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
