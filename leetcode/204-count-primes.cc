/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (30.01%)
 * Likes:    1727
 * Dislikes: 547
 * Total Accepted:    331.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Example:
 *
 *
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        if (n <= 3)
            return 1;
        vector<int> primes = {2};
        for (int i = 3; i < n; i++) {
            bool isPrime = true;
            for (int p : primes) {
                if (p * p > i)
                    break;
                if (i % p == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
                primes.push_back(i);
        }
        return primes.size();
    }
};
// @lc code=end
