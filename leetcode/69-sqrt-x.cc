/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (32.31%)
 * Likes:    1127
 * Dislikes: 1749
 * Total Accepted:    503.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 *
 * Example 1:
 *
 *
 * Input: 4
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 * the decimal part is truncated, 2 is returned.
 *
 *
 */
#include <cmath>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
  public:
    int mySqrt(int x) {
        if (x < 2)
            return x;

        int left = 0;
        int right = x;
        int mid;
        long tmp;
        while (left <= right) {
            mid = left + (right - left) / 2;
            tmp = long(mid) * long(mid);
            if (tmp == x)
                return mid;
            if (tmp > x)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
};
// @lc code=end

// 牛顿迭代法
class Solution2 {
  public:
int mySqrt(int x) {
    if (x < 2)
        return x;

    double x0 = x / 2;
    double x1 = (x0 + x / x0) / 2;
    while (int(x0) != int(x1)) {
        x0 = x1;
        x1 = (x0 + x / x0) / 2;
    }
    return int(x1);
}
};

int main() {
    Solution2 s;
    int r = s.mySqrt(2147395599);
    return 0;
}