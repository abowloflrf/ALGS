/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (57.40%)
 * Likes:    626
 * Dislikes: 1044
 * Total Accepted:    310K
 * Total Submissions: 519.4K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 *
 *
 * Note:
 *
 *
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 *
 *
 *
 */
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> S;
        unordered_set<int> resS;

        if (nums1.size() > nums2.size()) {
            for (int n : nums2)
                S.insert(n);
            for (int n : nums1) {
                if (S.find(n) != S.end())
                    resS.insert(n);
            }
        } else {
            for (int n : nums1)
                S.insert(n);
            for (int n : nums2) {
                if (S.find(n) != S.end())
                    resS.insert(n);
            }
        }

        vector<int> res;
        for (int n : resS) {
            res.push_back(n);
        }
        return res;
    }
};
// @lc code=end
