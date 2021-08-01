/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (40.53%)
 * Likes:    4301
 * Dislikes: 0
 * Total Accepted:    463.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 *
 * The overall run time complexity should be O(log (m+n)).
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 *
 *
 * Example 3:
 *
 *
 * Input: nums1 = [0,0], nums2 = [0,0]
 * Output: 0.00000
 *
 *
 * Example 4:
 *
 *
 * Input: nums1 = [], nums2 = [1]
 * Output: 1.00000
 *
 *
 * Example 5:
 *
 *
 * Input: nums1 = [2], nums2 = []
 * Output: 2.00000
 *
 *
 *
 * Constraints:
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int total = nums1.size() + nums2.size();
        int idx1 = 0;
        int idx2 = 0;
        int middle = 0;
        int preMiddle = 0;
        while ((idx1 + idx2) <= total / 2) {
            preMiddle = middle;
            if (idx1 < nums1.size() && idx2 < nums2.size()) {
                if (nums1[idx1] < nums2[idx2]) {
                    middle = nums1[idx1];
                    idx1++;
                } else {
                    middle = nums2[idx2];
                    idx2++;
                }
            } else if (idx1 < nums1.size()) {
                middle = nums1[idx1];
                idx1++;
            } else {
                middle = nums2[idx2];
                idx2++;
            }
        }
        if (total % 2) {
            return middle;
        }
        return (float(middle) + float(preMiddle)) / 2;
    }
    double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2) {
        nums2.insert(nums2.end(), nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int midIdx = nums2.size() / 2;
        if (nums2.size() % 2) {
            return nums2[midIdx];
        } else {
            return (float(nums2[midIdx]) + float(nums2[midIdx - 1])) / 2;
        }
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> n1 = {1, 2, 3};
    vector<int> n2 = {2, 3, 4};
    auto mid = s.findMedianSortedArrays2(n1, n2);
    return 0;
}
