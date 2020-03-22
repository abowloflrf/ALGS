/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 *
 * https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/
 *
 * algorithms
 * Medium (43.96%)
 * Likes:    311
 * Dislikes: 15
 * Total Accepted:    20.6K
 * Total Submissions: 45.5K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an array of integers A, a move consists of choosing any A[i], and
 * incrementing it by 1.
 *
 * Return the least number of moves to make every value in A unique.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [1,2,2]
 * Output: 1
 * Explanation:  After 1 move, the array could be [1, 2, 3].
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,1,2,1,7]
 * Output: 6
 * Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
 * It can be shown with 5 or less moves that it is impossible for the array to
 * have all unique values.
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 0 <= A.length <= 40000
 * 0 <= A[i] < 40000
 *
 *
 *
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int minIncrementForUnique(vector<int> &A) {
        int hash[80005] = {0};
        for (int n : A) {
            hash[n]++;
        }
        int res = 0;
        for (int i = 0; i < 80005; i++) {
            if (hash[i] > 1) {
                res += (hash[i] - 1);
                hash[i + 1] += (hash[i] - 1);
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> v = {1, 9, 9, 7};
    int r = s.minIncrementForUnique(v);
    return 0;
}