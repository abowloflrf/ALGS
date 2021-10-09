/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 *
 * https://leetcode-cn.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
 *
 * algorithms
 * Medium (45.12%)
 * Likes:    157
 * Dislikes: 0
 * Total Accepted:    18.3K
 * Total Submissions: 40.6K
 * Testcase Example:  '[30,20,150,100,40]'
 *
 * You are given a list of songs where the i^th song has a duration of time[i]
 * seconds.
 *
 * Return the number of pairs of songs for which their total duration in
 * seconds is divisible by 60. Formally, we want the number of indices i, j
 * such that i < j with (time[i] + time[j]) % 60 == 0.
 *
 *
 * Example 1:
 *
 *
 * Input: time = [30,20,150,100,40]
 * Output: 3
 * Explanation: Three pairs have a total duration divisible by 60:
 * (time[0] = 30, time[2] = 150): total duration 180
 * (time[1] = 20, time[3] = 100): total duration 120
 * (time[1] = 20, time[4] = 40): total duration 60
 *
 *
 * Example 2:
 *
 *
 * Input: time = [60,60,60]
 * Output: 3
 * Explanation: All three pairs have a total duration of 120, which is
 * divisible by 60.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= time.length <= 6 * 10^4
 * 1 <= time[i] <= 500
 *
 *
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int numPairsDivisibleBy60(vector<int> &time) {
        unordered_map<int, int> m;
        for (auto t : time) {
            m[t % 60]++;
        }
        int ans = 0;
        for (auto t : m) {
            if (t.first == 0 || t.first == 30) {
                ans = ans + t.second * (t.second - 1) / 2;
            } else {
                auto at = m.find(60 - t.first);
                if (at != m.end()) {
                    ans = ans + t.second * (at->second);
                    m.erase(at);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    /* code */
    Solution s;
    vector<int> data = {418, 204, 77, 278, 239, 457, 284, 263, 372, 279, 476, 416, 360, 18};
    s.numPairsDivisibleBy60(data);
    return 0;
}
