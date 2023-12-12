/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 *
 * https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/description/
 *
 * algorithms
 * Medium (44.54%)
 * Likes:    90
 * Dislikes: 0
 * Total Accepted:    35.3K
 * Total Submissions: 79.2K
 * Testcase Example:  '[5,1,3]\n[1,2,3,4,5]\n7'
 *
 * You are given two positive integer arrays spells and potions, of length n
 * and m respectively, where spells[i] represents the strength of the i^th
 * spell and potions[j] represents the strength of the j^th potion.
 *
 * You are also given an integer success. A spell and potion pair is considered
 * successful if the product of their strengths is at least success.
 *
 * Return an integer array pairs of length n where pairs[i] is the number of
 * potions that will form a successful pair with the i^th spell.
 *
 *
 * Example 1:
 *
 *
 * Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
 * Output: [4,0,3]
 * Explanation:
 * - 0^th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
 * - 1^st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
 * - 2^nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
 * Thus, [4,0,3] is returned.
 *
 *
 * Example 2:
 *
 *
 * Input: spells = [3,1,2], potions = [8,5,8], success = 16
 * Output: [2,0,2]
 * Explanation:
 * - 0^th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
 * - 1^st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful.
 * - 2^nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful.
 * Thus, [2,0,2] is returned.
 *
 *
 *
 * Constraints:
 *
 *
 * n == spells.length
 * m == potions.length
 * 1 <= n, m <= 10^5
 * 1 <= spells[i], potions[i] <= 10^5
 * 1 <= success <= 10^10
 *
 *
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        // 二分查找
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size());
        for (int i = 0; i < spells.size(); i++) {
            long s = spells[i];
            // 都满足或都不满足，就不找中间数了
            if (s * potions[0] >= success) {
                ans[i] = potions.size();
                continue;
            }
            if (s * potions.back() < success) {
                ans[i] = 0;
                continue;
            }
            int left = 0;
            int right = potions.size() - 1;
            // 找到一个 mid 使得坐标大于等于 mid 的 potion 都有效
            int mid = 0;
            while (left < right) {
                mid = left + (right - left) / 2;
                if (s * potions[mid] < success) {
                    left = mid + 1;
                } else if (s * potions[mid] > success) {
                    right = mid;
                } else {
                    break;
                }
            }

            if (s * potions[mid] < success && mid < (potions.size())) {
                mid++;
            }
            while (mid > 0 && (s * potions[mid - 1] == success)) {
                mid--;
            }

            ans[i] = potions.size() - mid;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    s.successfulPairs(spells, potions, 7);
    return 0;
}
