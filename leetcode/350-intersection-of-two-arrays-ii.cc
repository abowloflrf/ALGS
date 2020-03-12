/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (49.39%)
 * Likes:    1071
 * Dislikes: 352
 * Total Accepted:    296.4K
 * Total Submissions: 588.4K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 *
 *
 * Note:
 *
 *
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 *
 *
 * Follow up:
 *
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 *
 *
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for (int n : nums1) {
            if (m1.find(n) == m1.end())
                m1[n] = 1;
            else
                m1[n]++;
        }
        for (int n : nums2) {
            if (m2.find(n) == m1.end())
                m2[n] = 1;
            else
                m2[n]++;
        }
        vector<int> res;
        for (auto n : m1) {
            if (m2.find(n.first) != m2.end()) {
                int count = min(m1[n.first], m2[n.first]);
                while (count--)
                    res.push_back(n.first);
            }
        }
        return res;
    }
};
// @lc code=end
