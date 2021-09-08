
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> constructArr(vector<int> &a) {
        /**
         * N[0] = ---- * a[1] * a[2] * a[3] * a[4] * a[5]
         * N[1] = a[0] * ---- * a[2] * a[3] * a[4] * a[5]
         * N[2] = a[0] * a[1] * ---- * a[3] * a[4] * a[5]
         * N[3] = a[0] * a[1] * a[2] * ---- * a[4] * a[5]
         * N[4] = a[0] * a[1] * a[2] * a[3] * ---- * a[5]
         * N[5] = a[0] * a[1] * a[2] * a[3] * a[4] * ----
         * 
         * 分别计算上下两部分三角，可以累积乘
         */
        vector<int> top(a.size(), 1);
        vector<int> down(a.size(), 1);
        int tmpTop = 1, tmpDown = 1;
        for (int i = 1; i < a.size(); i++) {
            tmpDown *= a[i - 1];
            down[i] = tmpDown;

            tmpTop *= a[a.size() - i];
            top[a.size() - i - 1] = tmpTop;
        }

        vector<int> ans;
        for (int i = 0; i < a.size(); i++) {
            ans.push_back(top[i] * down[i]);
        }
        return ans;
    }
};