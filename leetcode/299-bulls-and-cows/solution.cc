/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] Bulls and Cows
 *
 * https://leetcode-cn.com/problems/bulls-and-cows/description/
 *
 * algorithms
 * Medium (50.38%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    29.3K
 * Total Submissions: 58.2K
 * Testcase Example:  '"1807"\n"7810"'
 *
 * You are playing the Bulls and Cows game with your friend.
 *
 * You write down a secret number and ask your friend to guess what the number
 * is. When your friend makes a guess, you provide a hint with the following
 * info:
 *
 *
 * The number of "bulls", which are digits in the guess that are in the correct
 * position.
 * The number of "cows", which are digits in the guess that are in your secret
 * number but are located in the wrong position. Specifically, the non-bull
 * digits in the guess that could be rearranged such that they become bulls.
 *
 *
 * Given the secret number secret and your friend's guess guess, return the
 * hint for your friend's guess.
 *
 * The hint should be formatted as "xAyB", where x is the number of bulls and y
 * is the number of cows. Note that both secret and guess may contain duplicate
 * digits.
 *
 *
 * Example 1:
 *
 *
 * Input: secret = "1807", guess = "7810"
 * Output: "1A3B"
 * Explanation: Bulls are connected with a '|' and cows are underlined:
 * "1807"
 * ⁠ |
 * "7810"
 *
 * Example 2:
 *
 *
 * Input: secret = "1123", guess = "0111"
 * Output: "1A1B"
 * Explanation: Bulls are connected with a '|' and cows are underlined:
 * "1123"        "1123"
 * ⁠ |      or     |
 * "0111"        "0111"
 * Note that only one of the two unmatched 1s is counted as a cow since the
 * non-bull digits can only be rearranged to allow one 1 to be a bull.
 *
 *
 * Example 3:
 *
 *
 * Input: secret = "1", guess = "0"
 * Output: "0A0B"
 *
 *
 * Example 4:
 *
 *
 * Input: secret = "1", guess = "1"
 * Output: "1A0B"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= secret.length, guess.length <= 1000
 * secret.length == guess.length
 * secret and guess consist of digits only.
 *
 *
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
  public:
    // input 只含数字，且size相等
    string getHint(string secret, string guess) {
        // A:位置数字一致
        // B:数字一致
        int charMap[10];
        for (int i = 0; i < 10; i++) {
            charMap[i] = 0;
        }
        for (char c : secret) {
            charMap[c - '0']++;
        }

        int a = 0, b = 0;
        for (int i = 0; i < guess.size(); i++) {
            // 统计位置数字均一致的数量
            if (secret[i] == guess[i]) {
                a++;
            }
            // 所有出现过且在secret中有足够数量的数字
            if (charMap[guess[i] - '0'] > 0) {
                charMap[guess[i] - '0']--;
                b++;
            }
        }
        // 减去位置对得上的，就是位置对不上的数字数量
        b = b - a;
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
// @lc code=end
