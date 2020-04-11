/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (39.69%)
 * Likes:    3079
 * Dislikes: 157
 * Total Accepted:    343K
 * Total Submissions: 832.5K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 *
 *
 *
 * Constraints:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 1 <= numCourses <= 10^5
 *
 *
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        int indegrees[numCourses]; //保存所有节点的入度
        vector<vector<int>> graph; //记录所有节点及其邻居
        queue<int> Q;              //保存所有入度为0的节点

        // 构造图并统计入度
        for (int i = 0; i < numCourses; i++) {
            indegrees[i] = 0;
            graph.push_back({});
        }
        for (auto p : prerequisites) {
            indegrees[p[0]]++;
            graph[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0)
                Q.push(i);
        }
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            numCourses--;
            for (auto current : graph[node]) {
                indegrees[current]--;
                if (indegrees[current] == 0)
                    Q.push(current);
            }
        }
        return numCourses == 0;
    }
};
// @lc code=end
