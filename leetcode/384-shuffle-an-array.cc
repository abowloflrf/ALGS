/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (51.10%)
 * Likes:    418
 * Dislikes: 887
 * Total Accepted:    107.8K
 * Total Submissions: 207.6K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 *
 *
 * Example:
 *
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 *
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 *
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 *
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    Solution(vector<int> &nums) {
        srand(time(nullptr));
        orignal = nums;
        randnums = vector<int>(nums);
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() { return orignal; }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (randnums.size() < 2)
            return randnums;
        for (int i = 0; i < randnums.size() - 1; i++) {
            swap(randnums[i], randnums[rand() % (randnums.size() - i)]);
        }
        return randnums;
    }

  private:
    vector<int> orignal;
    vector<int> randnums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
