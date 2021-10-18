/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] Rabbits in Forest
 *
 * https://leetcode-cn.com/problems/rabbits-in-forest/description/
 *
 * algorithms
 * Medium (61.69%)
 * Likes:    198
 * Dislikes: 0
 * Total Accepted:    43.3K
 * Total Submissions: 70.3K
 * Testcase Example:  '[1,1,2]'
 *
 * There is a forest with an unknown number of rabbits. We asked n rabbits "How
 * many rabbits have the same color as you?" and collected the answers in an
 * integer array answers where answers[i] is the answer of the i^th rabbit.
 *
 * Given the array answers, return the minimum number of rabbits that could be
 * in the forest.
 *
 *
 * Example 1:
 *
 *
 * Input: answers = [1,1,2]
 * Output: 5
 * Explanation:
 * The two rabbits that answered "1" could both be the same color, say red.
 * The rabbit that answered "2" can't be red or the answers would be
 * inconsistent.
 * Say the rabbit that answered "2" was blue.
 * Then there should be 2 other blue rabbits in the forest that didn't answer
 * into the array.
 * The smallest possible number of rabbits in the forest is therefore 5: 3 that
 * answered plus 2 that didn't.
 *
 *
 * Example 2:
 *
 *
 * Input: answers = [10,10,10]
 * Output: 11
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= answers.length <= 1000
 * 0 <= answers[i] < 1000
 *
 *
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int numRabbits(vector<int> &answers) {
        unordered_map<int, int> s;
        int ans = 0;
        for (int a : answers) {
            s[a]++;
        }
        for (auto p : s) {
            int group = p.first + 1;
            int k = p.second / group;
            if (group * k < p.second) {
                k++;
            }
            ans = ans + k * group;
        }
        return ans;
    }
};
// @lc code=end
