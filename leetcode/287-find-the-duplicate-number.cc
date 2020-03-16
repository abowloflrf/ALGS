/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (51.41%)
 * Likes:    3627
 * Dislikes: 450
 * Total Accepted:    270.8K
 * Total Submissions: 512.7K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Example 1:
 *
 *
 * Input: [1,3,4,2,2]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [3,1,3,4,2]
 * Output: 3
 *
 * Note:
 *
 *
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n^2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 *
 *
 */

#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == tmp)
                return tmp;
            tmp = nums[i];
        }
        return 0;
    }
};
// @lc code=end

// 空间 O(n)
// 时间 O(n)
class Solution2 {
  public:
    int findDuplicate(vector<int> &nums) {
        unordered_set<int> S;
        for (int n : nums) {
            if (S.find(n) == S.end())
                S.insert(n);
            else
                return n;
        }
        return 0;
    }
};

// 根据题意n+1个数所有数都在1-n之间
// 快慢指针 类似于检测链表是否有环
// 时间O(n) 空间 O(1)
class Solution3 {
  public:
    int findDuplicate(vector<int> &nums) {
        int fast = nums[nums[0]];
        int slow = nums[0];
        while (fast != slow) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        int a = 0, b = slow;
        while (a != b) {
            a = nums[a];
            b = nums[b];
        }
        return a;
    }
};