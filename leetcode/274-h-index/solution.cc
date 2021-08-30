/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H-Index
 *
 * https://leetcode-cn.com/problems/h-index/description/
 *
 * algorithms
 * Medium (44.03%)
 * Likes:    218
 * Dislikes: 0
 * Total Accepted:    52.4K
 * Total Submissions: 119.1K
 * Testcase Example:  '[3,0,6,1,5]'
 *
 * Given an array of integers citations where citations[i] is the number of
 * citations a researcher received for their i^th paper, return compute the
 * researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: A scientist has an
 * index h if h of their n papers have at least h citations each, and the other
 * n − h papers have no more than h citations each.
 *
 * If there are several possible values for h, the maximum one is taken as the
 * h-index.
 *
 *
 * Example 1:
 *
 *
 * Input: citations = [3,0,6,1,5]
 * Output: 3
 * Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each
 * of them had received 3, 0, 6, 1, 5 citations respectively.
 * Since the researcher has 3 papers with at least 3 citations each and the
 * remaining two with no more than 3 citations each, their h-index is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: citations = [1,3,1]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * n == citations.length
 * 1 <= n <= 5000
 * 0 <= citations[i] <= 1000
 *
 *
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        int h = 0;
        // for (int i = 1; i < citations.size(); i++) {
        //     if (citations[i] == citations[i - 1])
        //         continue;
        //     else if (citations[i - 1] >= i && i > h)
        //         h = i;
        // }

        // if (citations.back() >= citations.size() && citations.size() > h)
        //     return citations.size();

        // int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            int tmp = citations.size() - i;
            if (citations[i] >= tmp)
                return tmp;
        }
        return 0;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    vector<int> nums = {3, 0, 6, 1, 5};
    Solution s;
    s.hIndex(nums);
    return 0;
}
