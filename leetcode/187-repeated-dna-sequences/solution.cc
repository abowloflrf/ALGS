/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 *
 * https://leetcode-cn.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (48.44%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    63.1K
 * Total Submissions: 122.9K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * The DNA sequence is composed of a series of nucleotides abbreviated as 'A',
 * 'C', 'G', and 'T'.
 *
 *
 * For example, "ACGAATTCCG" is a DNA sequence.
 *
 *
 * When studying DNA, it is useful to identify repeated sequences within the
 * DNA.
 *
 * Given a string s that represents a DNA sequence, return all the
 * 10-letter-long sequences (substrings) that occur more than once in a DNA
 * molecule. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * Output: ["AAAAACCCCC","CCCCCAAAAA"]
 * Example 2:
 * Input: s = "AAAAAAAAAAAAA"
 * Output: ["AAAAAAAAAA"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is either 'A', 'C', 'G', or 'T'.
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
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> m;
        if (s.size() <= 10)
            return {};
        for (int i = 0; i <= s.size() - 10; i++) {
            string subs = s.substr(i, 10);
            auto iter = m.find(subs);
            if (iter != m.end()) {
                if (iter->second == 1) {
                    res.push_back(subs);
                }
                iter->second++;
            } else {
                m[subs] = 1;
            }
        }
        return res;
    }
};
// @lc code=end
