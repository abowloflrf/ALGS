# 77. 最小覆盖子串

### Version.1 无优化

```c++
class Solution {
  public:
    // b 是目标字符串 target
    // a 是经过的路径
    bool check(unordered_map<char, int> &a, unordered_map<char, int> &b) {
        for (auto t : b) {
            if (a[t.first] < t.second) {
                return false;
            }
        }
        return true;
    };

    string minWindow(string s, string t) {
        unordered_map<char, int> target, current;
        for (const char &c : t) {
            target[c]++;
        }

        int startIdx = 0;                             // 当前窗口
        int endIdx = 0;                               // 当前窗口
        int minWindow = 100001, ansL = -1, ansR = -1; // 结果

        while (endIdx < s.size()) {
            char c = s[endIdx];
            if (target.count(c)) {
                current[c]++;
            }

            while (check(current, target) && startIdx <= endIdx) {
                if (endIdx - startIdx + 1 < minWindow) {
                    minWindow = endIdx - startIdx + 1;
                    ansL = startIdx;
                    ansR = endIdx;
                }
                // startIdx++ 向右继续
                if (current.count(s[startIdx]) > 0)
                    current[s[startIdx]]--;
                startIdx++;
            }

            endIdx++;
        }
        return minWindow == 100001 ? "" : s.substr(ansL, minWindow);
    }
};
```

**结果**

-   执行用时： 100 ms 18.97%
-   内存消耗： 7.7 MB 44.56%

### Version.2 
