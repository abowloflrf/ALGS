/**
 * https://leetcode-cn.com/problems/smallest-k-lcci/
 * 找出数组中最小的k个数，任意顺序均可
 */

#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> smallestK(vector<int> &arr, int k) {
        if (k == 0)
            return {};

        priority_queue<int> q;
        for (int a : arr) {
            if (q.size() < k)
                q.push(a);
            else {
                if (q.top() > a) {
                    q.pop();
                    q.push(a);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};