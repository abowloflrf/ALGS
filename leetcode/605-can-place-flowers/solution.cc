/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] Can Place Flowers
 *
 * https://leetcode.cn/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (32.39%)
 * Likes:    688
 * Dislikes: 0
 * Total Accepted:    212.4K
 * Total Submissions: 655.7K
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * You have a long flowerbed in which some of the plots are planted, and some
 * are not. However, flowers cannot be planted in adjacent plots.
 *
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty
 * and 1 means not empty, and an integer n, return true if n new flowers can be
 * planted in the flowerbed without violating the no-adjacent-flowers rule and
 * false otherwise.
 *
 *
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: true
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= flowerbed.length <= 2 * 10^4
 * flowerbed[i] is 0 or 1.
 * There are no two adjacent flowers in flowerbed.
 * 0 <= n <= flowerbed.length
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int plant = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] != 0) {
                continue;
            }
            if ((i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                plant++;
            }
        }
        return plant >= n;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v = {0, 0, 1, 0, 1};
    s.canPlaceFlowers(v, 1);
    return 0;
}
