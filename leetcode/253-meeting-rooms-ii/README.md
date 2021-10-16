# 253. 会议室 II

给你一个会议时间安排的数组 `intervals` ，每个会议时间都会包括开始和结束的时间 `intervals[i] = [starti, endi]` ，为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。

```
输入：intervals = [[0,30],[5,10],[15,20]]
输出：2

输入：intervals = [[7,10],[2,4]]
输出：1
```

## 解法

1. 在一条时间线上记录所有入会、离会的时间点，以及该点的动作
2. 对该时间线进行排序
3. 一次遍历时间线，进行模拟的操作，维护同时最大容量

其中时间线可以由以下两种结构表示

-   `vector<pair<int, bool>>` pair 的第一个参数为时间点，第二个参数表示时开始会议还是结束会议
-   `map<int, int>` key 为时间点，value 为这个时间同时进行的 开始会议数-结束会议数，由于已经是 map ，插入时就已排好序，因此不必再次排序，直接模拟即可

**完整代码**

```c++
class Solution {
  public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        // 若不用 map ，也可以用 vector<pair<int,int>> first 为时间点，second 时 1/-1
        // 然后对 pair.first 进行排序
        vector<pair<int, bool>> v;
        for (auto &i : intervals) {
            v.push_back(make_pair(i[0], true));
            v.push_back(make_pair(i[1], false));
        }
        sort(v.begin(), v.end());

        // 记录完之后按时间顺序进行模拟操作，维护同时开始的最大会议室数量
        int ans = 0;
        int current = 0;
        for (auto &i : v) {
            if (i.second) {
                current++;
            } else {
                current--;
            }
            ans = max(current, ans);
        }
        return ans;
    }
};

```
