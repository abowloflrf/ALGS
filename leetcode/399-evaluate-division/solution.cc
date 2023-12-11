/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.cn/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (58.93%)
 * Likes:    1047
 * Dislikes: 0
 * Total Accepted:    87.5K
 * Total Submissions: 148.5K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * You are given an array of variable pairs equations and an array of real
 * numbers values, where equations[i] = [Ai, Bi] and values[i] represent the
 * equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a
 * single variable.
 *
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the
 * j^th query where you must find the answer for Cj / Dj = ?.
 *
 * Return the answers to all queries. If a single answer cannot be determined,
 * return -1.0.
 *
 * Note: The input is always valid. You may assume that evaluating the queries
 * will not result in division by zero and that there is no contradiction.
 *
 * Note: The variables that do not occur in the list of equations are
 * undefined, so the answer cannot be determined for them.
 *
 *
 * Example 1:
 *
 *
 * Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * Explanation:
 * Given: a / b = 2.0, b / c = 3.0
 * queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
 * note: x is undefined => -1.0
 *
 * Example 2:
 *
 *
 * Input: equations = [["a","b"],["b","c"],["bc","cd"]], values =
 * [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * Output: [3.75000,0.40000,5.00000,0.20000]
 *
 *
 * Example 3:
 *
 *
 * Input: equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * Output: [0.50000,2.00000,-1.00000,-1.00000]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= equations.length <= 20
 * equations[i].length == 2
 * 1 <= Ai.length, Bi.length <= 5
 * values.length == equations.length
 * 0.0 < values[i] <= 20.0
 * 1 <= queries.length <= 20
 * queries[i].length == 2
 * 1 <= Cj.length, Dj.length <= 5
 * Ai, Bi, Cj, Dj consist of lower case English letters and digits.
 *
 *
 */
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values,
                                vector<vector<string>> &queries) {
        // 组成一个有向图，正反向都有，正向为所给值，反向为其倒数 1/x
        //
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string start = equations[i][0];
            string end = equations[i][1];
            double val = values[i];
            graph[start][end] = val;
            graph[end][start] = 1 / val;
        }

        // 对每一个 query bfs 寻找最短路径并计算乘积
        // 答案初始化为 -1
        vector<double> ans(queries.size(), -1.0);
        for (int i = 0; i < queries.size(); i++) {
            // 图里没有这个节点，直接跳出
            if (graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end()) {
                continue;
            }
            queue<pair<string, double>> q;
            unordered_set<string> visited{queries[i][0]};
            q.push({queries[i][0], 1});
            while (!q.empty()) {
                bool found = false;
                auto node = q.front();
                q.pop();
                for (auto qq : graph[node.first]) {
                    if (qq.first == queries[i][1]) {
                        // 找到终点
                        ans[i] = qq.second * node.second;
                        found = true;
                        break;
                    } else {
                        // 未找到，加入到队列，继续寻找
                        if (visited.find(qq.first) == visited.end()) {
                            q.push({qq.first, node.second * qq.second});
                            visited.insert(qq.first);
                        }
                    }
                }
                if (found) {
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
