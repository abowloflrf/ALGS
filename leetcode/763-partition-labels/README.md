# 763. 划分字母区间

关键思路：使用 map 统计次数

## 解法 1

- 一个 `int f[128]` 统计整个字符串中所有字符出现的频率
- 再次遍历字符串，对于每一个区间再维护一个临时的 map 统计当前区间的字符频率 map，所有 k 的 value 均等于前面统计整个字符串的 value 时，完成一个区间的选择，清空临时 map，开始下一个 区间。

## 解法 2

- 一个 `int f[128]` 统计整个字符串每个字符最后出现的位置
- start end 两个位置维护当前的区间
- `end = max(end, f[c])` 且 `end == i` 时，即**维护当前段所有字符最大的最后出现位置**，这个操作能得到该区间是不是统计完所有的字符
- 若结束，下一段只需开始新的 `start = i + 1` 即可

```c++
class Solution {
  public:
    vector<int> partitionLabels(string s) {
        // 先走一遍记录每个字符最后一次出现的位置
        int f[128];
        memset(f, -1, sizeof(f));
        for (int i = 0; i < s.size(); i++) {
            f[s[i]] = i;
        }
        // 记录当前区间的 start end，每算完一个新的区间后更新 start
        int start = 0, end = 0;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            // 关键判断，维护当前段所有字符最大的最后出现位置，若到了这个位置说明结束
            end = max(end, f[s[i]]);
            if (end == i) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
```
