/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 *
 * https://leetcode.com/problems/distribute-candies-to-people/description/
 *
 * algorithms
 * Easy (60.09%)
 * Likes:    163
 * Dislikes: 46
 * Total Accepted:    18.8K
 * Total Submissions: 31.3K
 * Testcase Example:  '7\n4'
 *
 * We distribute some number of candies, to a row of n = num_people people in
 * the following way:
 *
 * We then give 1 candy to the first person, 2 candies to the second person,
 * and so on until we give n candies to the last person.
 *
 * Then, we go back to the start of the row, giving n + 1 candies to the first
 * person, n + 2 candies to the second person, and so on until we give 2 * n
 * candies to the last person.
 *
 * This process repeats (with us giving one more candy each time, and moving to
 * the start of the row after we reach the end) until we run out of candies.
 * The last person will receive all of our remaining candies (not necessarily
 * one more than the previous gift).
 *
 * Return an array (of length num_people and sum candies) that represents the
 * final distribution of candies.
 *
 *
 * Example 1:
 *
 *
 * Input: candies = 7, num_people = 4
 * Output: [1,2,3,1]
 * Explanation:
 * On the first turn, ans[0] += 1, and the array is [1,0,0,0].
 * On the second turn, ans[1] += 2, and the array is [1,2,0,0].
 * On the third turn, ans[2] += 3, and the array is [1,2,3,0].
 * On the fourth turn, ans[3] += 1 (because there is only one candy left), and
 * the final array is [1,2,3,1].
 *
 *
 * Example 2:
 *
 *
 * Input: candies = 10, num_people = 3
 * Output: [5,2,3]
 * Explanation:
 * On the first turn, ans[0] += 1, and the array is [1,0,0].
 * On the second turn, ans[1] += 2, and the array is [1,2,0].
 * On the third turn, ans[2] += 3, and the array is [1,2,3].
 * On the fourth turn, ans[0] += 4, and the final array is [5,2,3].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candies <= 10^9
 * 1 <= num_people <= 1000
 *
 *
 */

// 1. n*(n+1)/2
// 2. n*(3n+1)/2
// 3. n*(5n+1)/2
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> distributeCandies(int candies, int num_people) {
        int round = 0, total = 0;
        for (;;) {
            int num_to_plus = num_people * ((2 * round + 1) * num_people + 1) / 2;
            if ((total + num_to_plus) > candies) {
                break;
            } else {
                round++;
                total += num_to_plus;
            }
        }
        vector<int> result;
        if (round != 0) {
            for (int i = 1; i <= num_people; i++) {
                result.push_back(i * round + num_people * round * (round - 1) / 2);
            }
        } else {
            result = vector<int>(num_people, 0);
        }

        int left_candies = candies - total;
        for (int i = 0; i < num_people; i++) {
            int prepare = round * num_people + i + 1;
            if (prepare > left_candies) {
                result[i] += left_candies;
                break;
            }
            result[i] += prepare;
            left_candies -= prepare;
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    Solution s;
    auto r = s.distributeCandies(80, 4);
    for (auto i : r) {
        cout << i << ".";
    }
    return 0;
}
