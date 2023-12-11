/*
 * @lc app=leetcode.cn id=2542 lang=cpp
 *
 * [2542] Maximum Subsequence Score
 *
 * https://leetcode.cn/problems/maximum-subsequence-score/description/
 *
 * algorithms
 * Medium (51.53%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 12.2K
 * Testcase Example:  '[1,3,3,2]\n[2,1,3,4]\n3'
 *
 * You are given two 0-indexed integer arrays nums1 and nums2 of equal length n
 * and a positive integer k. You must choose a subsequence of indices from
 * nums1 of length k.
 *
 * For chosen indices i0, i1, ..., ik - 1, your score is defined as:
 *
 *
 * The sum of the selected elements from nums1 multiplied with the minimum of
 * the selected elements from nums2.
 * It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) *
 * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
 *
 *
 * Return the maximum possible score.
 *
 * A subsequence of indices of an array is a set that can be derived from the
 * set {0, 1, ..., n-1} by deleting some or no elements.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
 * Output: 12
 * Explanation:
 * The four possible subsequence scores are:
 * - We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
 * - We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6.
 * - We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12.
 * - We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
 * Therefore, we return the max score, which is 12.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
 * Output: 30
 * Explanation:
 * Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the
 * maximum possible score.
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums1.length == nums2.length
 * 1 <= n <= 10^5
 * 0 <= nums1[i], nums2[j] <= 10^5
 * 1 <= k <= n
 *
 *
 */
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        // 先从 nums2 入手，先算出对于给定 k 所有可能的最小 min(n2) 的情况
        // nums1 nums2 同时排序
        vector<pair<int, int>> data;
        for (int i = 0; i < nums1.size(); i++) {
            data.push_back({nums1[i], nums2[i]});
        }
        sort(data.begin(), data.end(), [](const auto &a, const auto &b) { return a.second > b.second; });
        // num2 可能的值：nums2[k-1]-nums[end]

        // 定义小根堆，维护最大的 k 个值
        priority_queue<int, vector<int>, greater<int>> pq;
        // s nums1 前 k 个和
        long long s = 0;
        for (int i = 0; i < k; i++) {
            s += data[i].first;
            pq.push(data[i].first);
        }
        long long ans = s * data[k - 1].second;
        // 遍历
        for (int i = k; i < nums1.size(); i++) {
            if (data[i].first > pq.top()) {
                s = s + data[i].first - pq.top();
                pq.pop();
                pq.push(data[i].first);
                ans = max(ans, s * data[i].second);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    vector<int> n1 = {1, 4};
    vector<int> n2 = {3, 1};
    Solution s;
    s.maxScore(n1, n2, 2);
    return 0;
}
