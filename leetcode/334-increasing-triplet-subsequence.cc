/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.68%)
 * Likes:    1284
 * Dislikes: 116
 * Total Accepted:    126.4K
 * Total Submissions: 317.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 *
 * Formally the function should:
 *
 * Return true if there exists i, j, k
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return
 * false.
 *
 * Note: Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: [1,2,3,4,5]
 * Output: true
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [5,4,3,2,1]
 * Output: false
 *
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool increasingTriplet(vector<int> &nums) {
        if (nums.size() < 3)
            return false;
        // 维护最小one，和倒数第二two两个数
        int one = INT32_MAX;
        int two = INT32_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > two)
                return true;
            if (nums[i] < one)
                one = nums[i];
            else if (nums[i] > one && nums[i] < two)
                two = nums[i];
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    Solution s;
    vector<int> v = {1, 1, -2, 6};
    s.increasingTriplet(v);
    return 0;
}
