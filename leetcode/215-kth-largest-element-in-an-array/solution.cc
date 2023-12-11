/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.70%)
 * Likes:    1217
 * Dislikes: 0
 * Total Accepted:    398.7K
 * Total Submissions: 616.2K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Given an integer array nums and an integer k, return the k^th largest
 * element in the array.
 *
 * Note that it is the k^th largest element in the sorted order, not the k^th
 * distinct element.
 *
 *
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start

class MinHeap {
  private:
    int cap;   // 由于使用原始 arrary，需要确定最大容量
    int size;  // 当前堆大小
    int *harr; // 使用数组保存

    int parent(int idx) { return (idx - 1) / 2; }
    int left(int idx) { return 2 * idx + 1; }
    int right(int idx) { return 2 * idx + 2; }

    void minHeapifyFromBottom(int idx) {
        if (idx == 0)
            return;
        int prtIdx = parent(idx);
        if (harr[prtIdx] > harr[idx]) {
            swap(harr[prtIdx], harr[idx]);
            minHeapifyFromBottom(prtIdx);
        }
    }
    // idx 与左右子节点比较，若 idx 有大于左右子节点，则与小的交换
    void minHeapifyFromTop(int idx) {
        int leftIdx = left(idx);
        int rightIdx = right(idx);

        int min = harr[idx];
        int minIdx = idx;
        if (leftIdx < size && harr[leftIdx] < min) {
            min = harr[leftIdx];
            minIdx = leftIdx;
        }
        if (rightIdx < size && harr[rightIdx] < min) {
            min = harr[rightIdx];
            minIdx = rightIdx;
        }
        if (minIdx == idx) {
            return;
        }
        swap(harr[idx], harr[minIdx]);
        minHeapifyFromTop(minIdx);
    }

  public:
    // 构造函数，初始化最小堆
    MinHeap(int c) {
        cap = c;
        harr = new int[cap];
        size = 0;
    }
    void push(int data) {
        if (size == cap) {
            return;
        }
        size++;
        harr[size - 1] = data;
        minHeapifyFromBottom(size - 1);
    }
    void pop() {
        if (size == 0)
            return;
        if (size == 1) {
            size = 0;
        }
        swap(harr[0], harr[size - 1]);
        size--;
        minHeapifyFromTop(0);
    }
    int top() {
        if (size == 0) {
            return -1;
        }
        return harr[0];
    }
    int heap_size() { return size; }
};

class Solution {
  public:
    // 1. 构造最小堆，堆大小维持在 k
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto const n : nums) {
            q.push(n);
            if (q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }
    // 2. 构造最大堆，最终堆大小为 nums.size()
    int findKthLargest2(vector<int> &nums, int k) {
        priority_queue<int> q;
        for (auto const n : nums) {
            q.push(n);
        }
        for (int i = 0; i < k - 1; i++) {
            q.pop();
        }
        return q.top();
    }
    // 3. 直接排序
    int findKthLargest3(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    // 4. 自己实现最小堆
    int findKthLargest4(vector<int> &nums, int k) {
        MinHeap h(nums.size());
        for (auto const i : nums) {
            h.push(i);
            if (h.heap_size() > k)
                h.pop();
        }
        return h.top();
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    vector<int> data = {3, 2, 1, 5, 6, 4};
    priority_queue<int> q;
    for (auto i : data) {
        q.push(i);
    }
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}
