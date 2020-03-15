/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (57.15%)
 * Likes:    2451
 * Dislikes: 168
 * Total Accepted:    323.8K
 * Total Submissions: 547.8K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Note:
 *
 *
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 *
 *
 */
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> M;
        for (int n : nums) {
            if (M.find(n) != M.end())
                M[n]++;
            else
                M[n] = 1;
        }
        struct cmp {
            bool operator()(const pair<int, int> &a, const pair<int, int> &b) { return a.second > b.second; };
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto m : M) {
            pq.push(m);
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ret(k);
        k--;
        while (!pq.empty()) {
            ret[k--] = pq.top().first;
            pq.pop();
        }
        return ret;
    }
};
// @lc code=end
