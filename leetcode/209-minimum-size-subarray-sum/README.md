# 209. 长度最小的子数组

全部为正整数的数组 nums，和一个 target，求满足子数组和不小于 target 的最小子数组

## 解法1: 前缀和

时间复杂度 $O(n^2)$

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int>  prefixSum(nums.size(), 0);
        int ans = INT32_MAX;
        for(int i = 0, prefix = 0;i < nums.size(); i++){
            prefix += nums[i];
            prefixSum[i] = prefix;
            // 这里可以用二分优化
            for (int j = i - 1 ;j >= 0;j--){
                if(prefix - prefixSum[j] >= target){
                    ans = min(ans, i - j);
                    break;
                }
            }
            // 若一致判断到首位还不满足，则判断该前缀本身是否符合
            if (prefix >= target) ans = min(ans, i + 1);
        }
        if (ans == INT32_MAX) return 0;
        return ans;
    }
};
```

若查询目标前缀使用二分查找优化，则时间复杂度可降低到 $O(n\log n)$

## 解法2: 滑动窗口

时间复杂度 $O(n)$

```c++
class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int start = 0, end = 0;
        int current = 0;
        int ans = INT32_MAX;
        while (end < nums.size()) {
            current += nums[end];
            while (current >= target) {
                ans = min(ans, end - start + 1);
                // 考虑到数组特性，start 其实一定不会超过 end，若到达 end 处则一定会跳出 while 循环继续加 end
                current -= nums[start++];
            }
            end++;
        }
        if (ans == INT32_MAX)
            return 0;
        return ans;
    }
};
```