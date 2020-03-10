/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 *
 * https://leetcode.com/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (25.73%)
 * Likes:    595
 * Dislikes: 63
 * Total Accepted:    13.3K
 * Total Submissions: 50.6K
 * Testcase Example:  '1\n2'
 *
 * You are given K eggs, and you have access to a building with N floors from 1
 * to N. 
 *
 * Each egg is identical in function, and if an egg breaks, you cannot drop it
 * again.
 *
 * You know that there exists a floor F with 0 <= F <= N such that any egg
 * dropped at a floor higher than F will break, and any egg dropped at or below
 * floor F will not break.
 *
 * Each move, you may take an egg (if you have an unbroken one) and drop it
 * from any floor X (with 1 <= X <= N). 
 *
 * Your goal is to know with certainty what the value of F is.
 *
 * What is the minimum number of moves that you need to know with certainty
 * what F is, regardless of the initial value of F?
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: K = 1, N = 2
 * Output: 2
 * Explanation:
 * Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
 * Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty
 * that F = 1.
 * If it didn't break, then we know with certainty F = 2.
 * Hence, we needed 2 moves in the worst case to know what F is with
 * certainty.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: K = 2, N = 6
 * Output: 3
 *
 *
 *
 * Example 3:
 *
 *
 * Input: K = 3, N = 14
 * Output: 4
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= K <= 100
 * 1 <= N <= 10000
 *
 *
 *
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
/**
 * 有K个鸡蛋和高N层的楼，当从X楼扔下时，
 * dp(K,N) = min X in 1...N ( max(dp(K-1,X-1), dp(K,N-X)) )
 *
 */
class Solution {
  public:
    int superEggDrop(int K, int N) {
        M = vector<vector<int>>(K + 1, vector<int>(N + 1, 0));
        return dp(K, N);
    }

  private:
    int dp(int K, int N) {
        if (K == 1)
            return N;
        if (N == 0)
            return 0;
        if (M[K][N] != 0)
            return M[K][N];

        int res = INT32_MAX;
        // 二分，而不是直接暴力从1...N
        int lo = 1, hi = N;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int isBroken = dp(K - 1, mid - 1);
            int notBroken = dp(K, N - mid);
            if (isBroken > notBroken) {
                hi = mid - 1;
                res = min(res, isBroken + 1);
            } else {
                lo = mid + 1;
                res = min(res, notBroken + 1);
            }
        }

        M[K][N] = res;
        return res;
    }
    vector<vector<int>> M;
};
// @lc code=end
