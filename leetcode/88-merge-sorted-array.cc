/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (38.03%)
 * Likes:    1697
 * Dislikes: 3601
 * Total Accepted:    496K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Note:
 *
 *
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 *
 *
 * Example:
 *
 *
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * Output: [1,2,2,3,5,6]
 *
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int indexA = m - 1;
        int indexB = n - 1;
        int index = m + n - 1;
        while (index >= 0) {
            if (indexA < 0) {
                nums1[index] = nums2[indexB];
                indexB--;
            } else if (indexB < 0) {
                nums1[index] = nums1[indexA];
                indexA--;
            } else if (nums1[indexA] > nums2[indexB]) {
                nums1[index] = nums1[indexA];
                indexA--;
            } else {
                nums1[index] = nums2[indexB];
                indexB--;
            }
            index--;
        }
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> vec1 = {1, 2, 3, 0, 0, 0};
    vector<int> vec2 = {2, 5, 6};
    s.merge(vec1, 3, vec2, 3);
}