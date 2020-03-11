/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 *
 * https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/description/
 *
 * algorithms
 * Easy (56.68%)
 * Likes:    287
 * Dislikes: 47
 * Total Accepted:    26.6K
 * Total Submissions: 46.5K
 * Testcase Example:  '[0,2,1,-6,6,-7,9,1,2,0,1]'
 *
 * Given an array A of integers, return true if and only if we can partition
 * the array into three non-empty parts with equal sums.
 *
 * Formally, we can partition the array if we can find indexes i+1 < j with
 * (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1]
 * + ... + A[A.length - 1])
 *
 *
 * Example 1:
 *
 *
 * Input: A = [0,2,1,-6,6,-7,9,1,2,0,1]
 * Output: true
 * Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
 *
 *
 * Example 2:
 *
 *
 * Input: A = [0,2,1,-6,6,7,9,-1,2,0,1]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: A = [3,3,6,5,-2,2,5,1,-9,4]
 * Output: true
 * Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= A.length <= 50000
 * -10^4 <= A[i] <= 10^4
 *
 *
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool canThreePartsEqualSum(vector<int> &A) {
        // 计算和的三分之一
        int sum = 0;
        for (auto n : A)
            sum += n;
        if (sum % 3 != 0)
            return false;
        int target = sum / 3;

        // 然后从数组前面往后遍历，找到两组和为sum/3即可
        sum = 0;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            // 找到第一组和为sum/3继续向下
            if (sum == target) {
                sum = 0;
                for (int j = i + 1; j < A.size(); j++) {
                    sum += A[j];
                    // j != A.size() - 1 这个条件很重要，若平分为两组相等了为0，第三组就没了
                    if (sum == target && j != A.size() - 1)
                        return true;
                }
                return false;
            }
        }
        return false;
    }
};
// @lc code=end
