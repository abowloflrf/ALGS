/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 *
 * https://leetcode-cn.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (51.75%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    80.1K
 * Total Submissions: 154.7K
 * Testcase Example:  '"1.01"\n"1.001"'
 *
 * Given two version numbers, version1 and version2, compare them.
 *
 *
 *
 *
 * Version numbers consist of one or more revisions joined by a dot '.'. Each
 * revision consists of digits and may contain leading zeros. Every revision
 * contains at least one character. Revisions are 0-indexed from left to right,
 * with the leftmost revision being revision 0, the next revision being
 * revision 1, and so on. For example 2.5.33 and 0.1 are valid version
 * numbers.
 *
 * To compare version numbers, compare their revisions in left-to-right order.
 * Revisions are compared using their integer value ignoring any leading zeros.
 * This means that revisions 1 and 001 are considered equal. If a version
 * number does not specify a revision at an index, then treat the revision as
 * 0. For example, version 1.0 is less than version 1.1 because their revision
 * 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.
 *
 * Return the following:
 *
 *
 * If version1 < version2, return -1.
 * If version1 > version2, return 1.
 * Otherwise, return 0.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: version1 = "1.01", version2 = "1.001"
 * Output: 0
 * Explanation: Ignoring leading zeroes, both "01" and "001" represent the same
 * integer "1".
 *
 *
 * Example 2:
 *
 *
 * Input: version1 = "1.0", version2 = "1.0.0"
 * Output: 0
 * Explanation: version1 does not specify revision 2, which means it is treated
 * as "0".
 *
 *
 * Example 3:
 *
 *
 * Input: version1 = "0.1", version2 = "1.1"
 * Output: -1
 * Explanation: version1's revision 0 is "0", while version2's revision 0 is
 * "1". 0 < 1, so version1 < version2.
 *
 *
 * Example 4:
 *
 *
 * Input: version1 = "1.0.1", version2 = "1"
 * Output: 1
 *
 *
 * Example 5:
 *
 *
 * Input: version1 = "7.5.2.4", version2 = "7.5.3"
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= version1.length, version2.length <= 500
 * version1 and version2 only contain digits and '.'.
 * version1 and version2 are valid version numbers.
 * All the given revisions in version1 and version2 can be stored in a 32-bit
 * integer.
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int compareVersion(string version1, string version2) {
        vector<int> v1s = parseVersion(version1);
        vector<int> v2s = parseVersion(version2);

        for (int i = 0; i < v1s.size() && i < v2s.size(); i++) {
            if (v1s[i] > v2s[i])
                return 1;
            else if (v1s[i] < v2s[i])
                return -1;
        }
        if (v1s.size() > v2s.size()) {
            for (int i = v2s.size(); i < v1s.size(); i++) {
                if (v1s[i] != 0)
                    return 1;
            }
            return 0;
        }

        if (v1s.size() < v2s.size()) {
            for (int i = v1s.size(); i < v2s.size(); i++) {
                if (v2s[i] != 0)
                    return -1;
            }
            return 0;
        }
        return 0;
    }

  private:
    vector<int> parseVersion(string version) {
        vector<int> v;
        int currN = 0;
        for (char c : version) {
            if (currN == 0 && c == '0')
                continue;
            if (c != '.') {
                currN = currN * 10 + (c - '0');
            } else {
                v.push_back(currN);
                currN = 0;
            }
        }
        if (currN != 0)
            v.push_back(currN);
        return v;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    int a1 = s.compareVersion("1.01", "1.001");
    int a2 = s.compareVersion("1.0", "1.0.0");
    int a3 = s.compareVersion("1.1", "0.1");
    int a4 = s.compareVersion("1.0.1", "1");
    int a5 = s.compareVersion("7.5.2.4", "7.5.3");
    int a6 = s.compareVersion("7.5.3.4", "7.5.3");
    int a7 = s.compareVersion("0", "1");
    return 0;
}
