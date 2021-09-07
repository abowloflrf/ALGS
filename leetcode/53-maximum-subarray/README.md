# 53.最大子序列和

[最大子序列问题 - Wikipedia](https://zh.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E5%AD%90%E6%95%B0%E5%88%97%E9%97%AE%E9%A2%98)

一遍循环，每次判断以改节点为重点的最大子序列是多少，同时每时每刻还需要知道上一个节点为重点的最大子序列和（以 `currentSum` 维护），`ans` 保存最终结果。

本质是 dp ，即 `dp[N]` 为以第 N 个元素结尾的最大自序列和，本应当是用一个 `dp[N]` 的数组去保存历史结果的，但是其实在循环中每次只需要上一次的结果就行，因此省略了一维 dp 的数组，直接用一个单独的变量去维护。

```c++
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int currentSum = nums[0];
        int ans = currentSum;
        for (int i = 1; i < nums.size(); i++) {
            // 1. 若取前 n-1 ，则直接连续上
            // 2. 若不取，则只取 N
            // 判断两种情况谁受益最大选谁
            currentSum = max(nums[i] + currentSum, nums[i]);
            ans = max(ans, currentSum);
        }
        return ans;
    }
};
```
