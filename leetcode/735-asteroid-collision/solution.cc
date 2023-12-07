/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] Asteroid Collision
 *
 * https://leetcode.cn/problems/asteroid-collision/description/
 *
 * algorithms
 * Medium (42.47%)
 * Likes:    460
 * Dislikes: 0
 * Total Accepted:    85.6K
 * Total Submissions: 201.6K
 * Testcase Example:  '[5,10,-5]'
 *
 * We are given an array asteroids of integers representing asteroids in a
 * row.
 *
 * For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 *
 * Find out the state of the asteroids after all collisions. If two asteroids
 * meet, the smaller one will explode. If both are the same size, both will
 * explode. Two asteroids moving in the same direction will never meet.
 *
 *
 * Example 1:
 *
 *
 * Input: asteroids = [5,10,-5]
 * Output: [5,10]
 * Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never
 * collide.
 *
 *
 * Example 2:
 *
 *
 * Input: asteroids = [8,-8]
 * Output: []
 * Explanation: The 8 and -8 collide exploding each other.
 *
 *
 * Example 3:
 *
 *
 * Input: asteroids = [10,2,-5]
 * Output: [10]
 * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
 * resulting in 10.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= asteroids.length <= 10^4
 * -1000 <= asteroids[i] <= 1000
 * asteroids[i] != 0
 *
 *
 */
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> ans;
        for (const auto &a : asteroids) {
            // 碰撞，需要循环处理完所有现存的
            bool reserve = true;
            while (ans.empty() || (ans.back() > 0 && a < 0)) {
                if (ans.empty()) {
                    break;
                }
                if (ans.back() < -a) {
                    // 后来的比较大，继续检查下一个
                    ans.pop_back();
                    continue;
                } else if (ans.back() > -a) {
                    // 后来的比较小，直接没了
                    reserve = false;
                    break;
                } else if (ans.back() == -a) {
                    // 一样大，都没了
                    reserve = false;
                    ans.pop_back();
                    break;
                }
            }
            if (reserve) {
                ans.push_back(a);
            }
        }
        return ans;
    }
};
// @lc code=end
