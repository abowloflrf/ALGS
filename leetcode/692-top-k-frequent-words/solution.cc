/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode-cn.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (57.73%)
 * Likes:    396
 * Dislikes: 0
 * Total Accepted:    68.7K
 * Total Submissions: 119K
 * Testcase Example:  '["i","love","leetcode","i","love","coding"]\n2'
 *
 * Given an array of strings words and an integer k, return the k most frequent
 * strings.
 *
 * Return the answer sorted by the frequency from highest to lowest. Sort the
 * words with the same frequency by their lexicographical order.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["i","love","leetcode","i","love","coding"], k = 2
 * Output: ["i","love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * Note that "i" comes before "love" due to a lower alphabetical order.
 *
 *
 * Example 2:
 *
 *
 * Input: words =
 * ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
 * Output: ["the","is","sunny","day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 500
 * 1 <= words[i] <= 10
 * words[i] consists of lowercase English letters.
 * k is in the range [1, The number of unique words[i]]
 *
 *
 *
 * Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
 *
 */
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> m;
        for (auto &s : words) {
            m[s]++;
        }

        // 自定义优先队列排序方法
        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
            // 相同时，还要按单词字典序排序
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };

        // 创建小跟堆，最小的在堆顶，满时 pop 堆顶
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
        for (auto p : m) {
            q.push(make_pair(p.first, p.second));
            if (q.size() > k) {
                q.pop();
            }
        }

        vector<string> ans(k);
        for (int i = 0; i < k; i++) {
            ans[k - i - 1] = q.top().first;
            q.pop();
        }

        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    s.topKFrequent(words, 2);
    return 0;
}
