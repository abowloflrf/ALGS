
#include <map>
#include <vector>
using namespace std;

class Solution {
  public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        // map 有序，省去了排序
        // key 为时间点，入会时间点 value+1，离会时间点 value-1
        // 记录所有时间点的操作

        // 若不用 map ，也可以用 vector<pair<int,int>> first 为时间点，second 时 1/-1
        // 然后对 pair.first 进行排序
        map<int, int> m;
        for (auto &i : intervals) {
            m[i[0]]++;
            m[i[1]]--;
        }

        // 记录完之后按时间顺序进行模拟操作，维护同时开始的最大会议室数量
        int ans = 0;
        int current = 0;
        for (auto &i : m) {
            current += i.second;
            ans = max(current, ans);
        }
        return ans;
    }
};

class Solution2 {
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
