/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] Integer to Roman
 *
 * https://leetcode-cn.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (66.57%)
 * Likes:    671
 * Dislikes: 0
 * Total Accepted:    213.6K
 * Total Submissions: 320.8K
 * Testcase Example:  '3'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 *
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, 2 is written as II in Roman numeral, just two one's added
 * together. 12 is written as XII, which is simply X + II. The number 27 is
 * written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 *
 * Given an integer, convert it to a roman numeral.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 3
 * Output: "III"
 *
 *
 * Example 2:
 *
 *
 * Input: num = 4
 * Output: "IV"
 *
 *
 * Example 3:
 *
 *
 * Input: num = 9
 * Output: "IX"
 *
 *
 * Example 4:
 *
 *
 * Input: num = 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 *
 *
 * Example 5:
 *
 *
 * Input: num = 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num <= 3999
 *
 *
 */
#include <string>
using namespace std;

// @lc code=start

class Map {
  public:
    string symbol;
    int number;
    Map(string s, int n) {
        symbol = s;
        number = n;
    }
};

class Solution {
  public:
    string intToRoman(int num) {
        Map symbols[] = {Map("M", 1000), Map("CM", 900), Map("D", 500), Map("CD", 400), Map("C", 100),
                         Map("XC", 90),  Map("L", 50),   Map("XL", 40), Map("X", 10),   Map("IX", 9),
                         Map("V", 5),    Map("IV", 4),   Map("I", 1)};

        string res;
        while (num != 0) {
            for (auto s : symbols) {
                if (num >= s.number) {
                    res += s.symbol;
                    num -= s.number;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    string res = s.intToRoman(1234);
    return 0;
}
