/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode-cn.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (71.08%)
 * Likes:    327
 * Dislikes: 0
 * Total Accepted:    78.1K
 * Total Submissions: 109.8K
 * Testcase Example:  '"tree"'
 *
 * Given a string s, sort it in decreasing order based on the frequency of
 * characters, and return the sorted string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "tree"
 * Output: "eert"
 * Explanation: 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cccaaa"
 * Output: "aaaccc"
 * Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also a
 * valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "Aabb"
 * Output: "bbAa"
 * Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^5
 * s consists of English letters and digits.
 *
 *
 */
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    string frequencySort(string s) {
        int charcnt[128];
        for (int i = 0; i < 128; i++)
            charcnt[i] = 0;
        for (char c : s)
            charcnt[c]++;
        multimap<int, string, greater<int>> charsort;
        for (int i = 0; i < 128; i++) {
            if (charcnt[i] == 0)
                continue;
            string str = "";
            for (int j = 0; j < charcnt[i]; j++) {
                str.push_back('\0' + i);
            }
            charsort.insert(make_pair(charcnt[i], str));
        }
        string res;
        for (auto p : charsort) {
            res += p.second;
        }
        return res;
    }
};

// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    string ans = s.frequencySort("abcabaal");
    return 0;
}