/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (54.56%)
 * Likes:    2511
 * Dislikes: 206
 * Total Accepted:    515.1K
 * Total Submissions: 920K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 */

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> m;
        int half = nums.size() / 2;
        for (auto n : nums) {
            if (m.find(n) == m.end())
                m.insert({n, 1});
            else
                m[n]++;
            if (m[n] > half)
                return n;
        }
        return -1;
    }
};
// @lc code=end

// 1. 暴力算法
// 2. hash表统计
// 3. 排序
// 4. 投票算法

class Solution2 {
  public:
    // 排序之后判断位于 n/2 位置的元素一定为众数
    int majorityElement(vector<int> &numbers) {
        if (numbers.empty())
            return -1;
        int length = numbers.size();
        int start = 0;
        int end = length - 1;

        int index = partition(numbers, start, end);
        int middle = length >> 1;
        while (index != middle) {
            //中位数在右边
            if (index > middle) {
                end = index - 1;
                index = partition(numbers, start, end);
            } else {
                start = index + 1;
                index = partition(numbers, start, end);
            }
        }

        int result = numbers[middle];
        return result;
    }

  private:
    int partition(vector<int> &numbers, int start, int end) {
        int target = numbers[end];

        int left = start;
        int right = end - 1;

        while (left < right) {
            while (numbers[left] < target && left < right)
                left++;
            while (numbers[right] >= target && left < right)
                right--;
            swap(numbers[left], numbers[right]);
        }
        if (numbers[left] >= numbers[end])
            swap(numbers[left], numbers[end]);
        else
            left++;
        return left;
    }
};