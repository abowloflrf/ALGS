/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (43.20%)
 * Likes:    1441
 * Dislikes: 55
 * Total Accepted:    204.5K
 * Total Submissions: 455.2K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * Example:
 *
 *
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 *
 *
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        helper(s, 0, tmp, res);
        return res;
    }

  private:
    void helper(string &a, int start, vector<string> &cur, vector<vector<string>> &res) {
        if (start == a.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < a.size(); i++) {
            string left = a.substr(start, i + 1 - start);
            if (isPalindrome(left)) {
                cur.push_back(left);
                helper(a, i + 1, cur, res);
                cur.pop_back();
            }
        }
    }
    bool isPalindrome(string &a) {
        int start = 0;
        int end = a.size() - 1;
        while (start < end) {
            if (a[start++] != a[end--])
                return false;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution s;
    auto r = s.partition("aab");
    return 0;
}
