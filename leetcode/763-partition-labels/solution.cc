/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * https://leetcode-cn.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (76.32%)
 * Likes:    584
 * Dislikes: 0
 * Total Accepted:    83.2K
 * Total Submissions: 109.1K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * You are given a string s. We want to partition the string into as many parts
 * as possible so that each letter appears in at most one part.
 *
 * Return a list of integers representing the size of these parts.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits s into less parts.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "eccbbbbdec"
 * Output: [10]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 *
 *
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> partitionLabels(string s) {
        // 先走一遍统计字符次数
        int f[128];
        memset(f, 0, sizeof(f));
        for (char c : s) {
            f[c]++;
        }

        vector<int> ans;
        unordered_map<int, int> tmpMap;
        int tmpSize = 0;
        for (char c : s) {
            tmpMap[c]++;
            tmpSize++;
            bool done = true;
            for (auto p : tmpMap) {
                if (f[p.first] != p.second) {
                    done = false;
                    break;
                }
            }
            if (done) {
                ans.push_back(tmpSize);
                tmpSize = 0;
                tmpMap.clear();
            }
        }
        return ans;
    }
};
// @lc code=end

class Solution2 {
  public:
    vector<int> partitionLabels(string s) {
        // 先走一遍记录每个字符最后一次出现的位置
        int f[128];
        memset(f, -1, sizeof(f));
        for (int i = 0; i < s.size(); i++) {
            f[s[i]] = i;
        }
        // 记录当前区间的 start end，每算完一个新的区间后更新 start
        int start = 0, end = 0;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, f[s[i]]);
            if (end == i) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {

    Solution s;
    s.partitionLabels("ababcbacadefegdehijhklij");
    return 0;
}
