# 218. 天际线问题

类似于 986 ，是 986 的升级版。

-   一个 `vector<pair<int, int>>` 记录所有楼的 起始、结束 与 高度的对应关系，为了方便区分是开始还是结束可以用正负高度值来区分
-   常规思路是起始高度为正，但是这题起始设置为负较为方便，因为 pair 的排序在 first 相同时，second 小的排在前面，但是我们希望同一横坐标在遍历时先取到较高的楼，因此起始设置高度为 -h，结束设置为 +h
-   对维护好的序列按横坐标排序
-   创建一个 `multiset<int>` 在横坐标前进模拟时维护前面的最高值
-   `s.rbegin()` 是反向迭代器，指向末尾元素，在这里即为最大的元素
-   遍历时若最高高度又变化，则加入到结果集坐标中

**完整代码**

```c++
class Solution {
  public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> v;
        for (auto &b : buildings) {
            // 楼开始设置为负数的原因是，pair 排序在 first 相等时，再按 second 小的在前
            // 但是实际上希望同一横坐标，最高的在前面
            v.push_back(make_pair(b[0], -b[2])); // 楼开始
            v.push_back(make_pair(b[1], b[2]));  // 楼结束
        }
        sort(v.begin(), v.end());

        // multiset 已经排好序，从前向后遍历，维护当时的最高值
        vector<vector<int>> ans;
        multiset<int> s;
        int prev = 0;
        for (auto &item : v) {
            if (item.second > 0) {
                s.erase(s.find(item.second));
            } else {
                s.insert(-item.second);
            }
            int h = 0;
            if (!s.empty())
                h = *s.rbegin();
            if (h != prev) {
                ans.push_back({item.first, h});
                prev = h;
            }
        }
        return ans;
    }
};
```
