/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 *
 * https://leetcode.com/problems/water-and-jug-problem/description/
 *
 * algorithms
 * Medium (29.62%)
 * Likes:    239
 * Dislikes: 662
 * Total Accepted:    35.7K
 * Total Submissions: 118.5K
 * Testcase Example:  '3\n5\n4'
 *
 * You are given two jugs with capacities x and y litres. There is an infinite
 * amount of water supply available. You need to determine whether it is
 * possible to measure exactly z litres using these two jugs.
 *
 * If z liters of water is measurable, you must have z liters of water
 * contained within one or both buckets by the end.
 *
 * Operations allowed:
 *
 *
 * Fill any of the jugs completely with water.
 * Empty any of the jugs.
 * Pour water from one jug into another till the other jug is completely full
 * or the first jug itself is empty.
 *
 *
 * Example 1: (From the famous "Die Hard" example)
 *
 *
 * Input: x = 3, y = 5, z = 4
 * Output: True
 *
 *
 * Example 2:
 *
 *
 * Input: x = 2, y = 6, z = 5
 * Output: False
 *
 */
#include <queue>
#include <unordered_set>
using namespace std;
using PII = pair<int, int>;

// 数学方法
class Solution1 {
  public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z)
            return false;
        if (x == 0 || y == 0)
            return z == 0 || x + y == z;
        return z % gcd(x, y) == 0;
    }

  private:
    int gcd(int a, int b) //辗转相除法
    {
        if (a % b == 0)
            return b;
        return gcd(b, a % b);
    }
};

// @lc code=start
class Solution {
    struct HashPair {
        size_t operator()(const pair<int, int> &key) const noexcept { return key.first ^ key.second; }
    };

  public:
    bool canMeasureWater(int x, int y, int z) {
        queue<pair<int, int>> q;
        unordered_set<pair<int, int>, HashPair> visited;
        q.push({0, 0});
        visited.insert({0, 0});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            // 可获得z的情况
            if (z == p.first || z == p.second || z == p.first + p.second)
                return true;

            // 遍历所有情况
            vector<pair<int, int>> items = {{x, p.second}, {p.first, y}, {0, p.second}, {p.first, 0}};
            if (p.first + p.second >= x)
                items.push_back({x, p.second + p.first - x});
            else
                items.push_back({x + p.second, 0});
            if (p.first + p.second >= y)
                items.push_back({p.first + p.second - y, y});
            else
                items.push_back({0, p.second + p.first});
            for (auto item : items) {
                if (visited.find(item) == visited.end()) {
                    q.push(item);
                    visited.insert(item);
                }
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution s;
    bool r = s.canMeasureWater(2, 6, 5);
    return 0;
}