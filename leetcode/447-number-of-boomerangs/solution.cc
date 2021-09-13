/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 *
 * https://leetcode-cn.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Medium (60.45%)
 * Likes:    194
 * Dislikes: 0
 * Total Accepted:    38.7K
 * Total Submissions: 59.6K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * You are given n points in the plane that are all distinct, where points[i] =
 * [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance
 * between i and j equals the distance between i and k (the order of the tuple
 * matters).
 *
 * Return the number of boomerangs.
 *
 *
 * Example 1:
 *
 *
 * Input: points = [[0,0],[1,0],[2,0]]
 * Output: 2
 * Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and
 * [[1,0],[2,0],[0,0]].
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: points = [[1,1]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * n == points.length
 * 1 <= n <= 500
 * points[i].length == 2
 * -10^4 <= xi, yi <= 10^4
 * All the points are unique.
 *
 *
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int numberOfBoomerangs(vector<vector<int>> &points) {
        int ans = 0;
        for (auto p : points) {
            // 假设 p 为拐点，在所有 points 中寻找另外两个点
            // 记录 距离 -> 点的数量
            unordered_map<int, int> M;
            for (auto i : points) {
                if (i == p)
                    continue;
                int distance = (i[0] - p[0]) * (i[0] - p[0]) + (i[1] - p[1]) * (i[1] - p[1]);
                M[distance]++;
            }
            // 在记录的 map 中寻找，相同距离点数大于 2 的表示至少可以构成一个回旋镖
            // 顺序不同代表的回旋镖也不一样，因此数量 m*(m-1)
            for (auto i : M) {
                if (i.second > 1) {
                    ans += (i.second * (i.second - 1));
                }
            }
        }
        return ans;
    }
};
// @lc code=end
