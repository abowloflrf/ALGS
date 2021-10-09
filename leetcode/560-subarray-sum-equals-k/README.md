# 560. 和为 K 的子数组

## 暴力

直接超时

## 维护前缀和 + hash

前缀和：以 0 开头前 n 个数的和

```c++
unordered_map<int, int> h = {{0, 1}};
```

`Map<a,b>` 前缀和为 a 的前缀和的数量 b，注意初始化时需要有个 `{0,1}` 的初始值

```c++
class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int ans = 0;
        int prefixSum = 0;
        // 前缀和 value => count 的映射
        // 记得初始有 0->1
        unordered_map<int, int> h = {{0, 1}};
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            auto iter = h.find(prefixSum - k);
            if (iter != h.end()) {
                ans += iter->second;
            }
            h[prefixSum]++;
        }
        return ans;
    }
};
```
