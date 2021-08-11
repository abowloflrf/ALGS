/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (62.19%)
 * Likes:    827
 * Dislikes: 0
 * Total Accepted:    185.4K
 * Total Submissions: 298.1K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 *
 *
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 *
 */
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start

class Pair {
  public:
    int a, b;
    Pair(int aa, int bb) {
        a = aa;
        b = bb;
    }
};

bool operator>(const Pair &a, const Pair &b) { return a.b > b.b; }

class Solution {
  public:
    // 使用 map 和 堆
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        priority_queue<Pair, vector<Pair>, greater<Pair>> q;
        for (const int n : nums) {
            count[n]++;
        }
        for (auto c : count) {
            q.push(Pair(c.first, c.second));
            if (q.size() > k) {
                q.pop();
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().a);
            q.pop();
        }
        return res;
    }
};
// @lc code=end
