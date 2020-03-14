/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 *
 * https://leetcode.com/problems/4sum-ii/description/
 *
 * algorithms
 * Medium (51.69%)
 * Likes:    953
 * Dislikes: 68
 * Total Accepted:    94.1K
 * Total Submissions: 179.5K
 * Testcase Example:  '[1,2]\n[-2,-1]\n[-1,2]\n[0,2]'
 *
 * Given four lists A, B, C, D of integer values, compute how many tuples (i,
 * j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 *
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤
 * N ≤ 500. All integers are in the range of -2^28 to 2^28 - 1 and the result
 * is guaranteed to be at most 2^31 - 1.
 *
 * Example:
 *
 *
 * Input:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 *
 *
 *
 *
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        unordered_map<int, int> mapAB;
        for (auto a : A)
            for (auto b : B) {
                int sumAB = a + b;
                if (mapAB.find(sumAB) != mapAB.end())
                    mapAB[sumAB]++;
                else
                    mapAB[sumAB] = 1;
            }
        int res = 0;
        for (auto c : C)
            for (auto d : D) {
                int sumCD = c + d;
                if (mapAB.find(-sumCD) != mapAB.end()) {
                    res += mapAB[-sumCD];
                }
            }
        return res;
    }
};
// @lc code=end
