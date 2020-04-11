/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (36.76%)
 * Likes:    1721
 * Dislikes: 117
 * Total Accepted:    224.6K
 * Total Submissions: 583.7K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 *
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 *
 * Example 1:
 *
 *
 * Input: 2, [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished
 * course 0. So the correct course order is [0,1] .
 *
 * Example 2:
 *
 *
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
 * finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3] .
 *
 * Note:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 *
 *
 */
#include <queue>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        int indegrees[numCourses]; //保存所有节点的入度
        vector<vector<int>> graph; //记录所有节点及其邻居
        queue<int> Q;              //保存所有入度为0的节点
        vector<int> res;

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
            res.push_back(node);
            for (auto current : graph[node]) {
                indegrees[current]--;
                if (indegrees[current] == 0)
                    Q.push(current);
            }
        }
        if (res.size() != numCourses)
            return {};
        return res;
    }
};
// @lc code=end
