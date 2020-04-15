/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (33.64%)
 * Likes:    1495
 * Dislikes: 4265
 * Total Accepted:    429K
 * Total Submissions: 1.2M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        vector<string> res(numRows);
        // numRows + (numRows - 2) 为一组
        int idxRow = 0;
        bool toUp = true;
        for (char c : s) {
            res[idxRow].push_back(c);

            if (idxRow == numRows - 1 || idxRow == 0) {
                toUp = !toUp;
            }
            if (toUp) {
                idxRow -= 1;
            } else {
                idxRow += 1;
            }
        }

        string ans;
        for (string s : res) {
            ans += s;
        }
        return ans;
    }
};
// @lc code=end
