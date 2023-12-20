/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] Powerful Integers
 *
 * https://leetcode.cn/problems/powerful-integers/description/
 *
 * algorithms
 * Medium (41.14%)
 * Likes:    57
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 30.6K
 * Testcase Example:  '2\n3\n10'
 *
 * Given three integers x, y, and bound, return a list of all the powerful
 * integers that have a value less than or equal to bound.
 *
 * An integer is powerful if it can be represented as x^i + y^j for some
 * integers i >= 0 and j >= 0.
 *
 * You may return the answer in any order. In your answer, each value should
 * occur at most once.
 *
 *
 * Example 1:
 *
 *
 * Input: x = 2, y = 3, bound = 10
 * Output: [2,3,4,5,7,9,10]
 * Explanation:
 * 2 = 2^0 + 3^0
 * 3 = 2^1 + 3^0
 * 4 = 2^0 + 3^1
 * 5 = 2^1 + 3^1
 * 7 = 2^2 + 3^1
 * 9 = 2^3 + 3^0
 * 10 = 2^0 + 3^2
 *
 *
 * Example 2:
 *
 *
 * Input: x = 3, y = 5, bound = 15
 * Output: [2,4,6,8,10,14]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= x, y <= 100
 * 0 <= bound <= 10^6
 *
 *
 */
#include <cmath>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> uans;
        vector<int> ans;
        int x1 = 0;
        for (;; x1++) {
            int s = pow(x, x1);
            if (s > bound)
                break;
            int y1 = 0;
            for (;; y1++) {
                int s2 = s + pow(y, y1);
                if (s2 <= bound)
                    uans.insert(s2);
                else
                    break;

                if (y == 0 || y == 1)
                    break;
            }
            // 避免陷入死循环，1和2作为底数永远无法break
            if (x == 0 || x == 1)
                break;
        }
        ans.insert(ans.end(), uans.begin(), uans.end());
        return ans;
    }
};
// @lc code=end
