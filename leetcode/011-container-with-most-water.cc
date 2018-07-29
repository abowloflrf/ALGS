//
// Created by ruofeng on 2018/7/29.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while (left < right) {
            int h = min(height[right], height[left]);
            res = max(res, h * (right - left));
            while (height[left] <= h && left < right) left++;
            while (height[right] <= h && left < right) right--;
        }
        return res;
    }
};

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.maxArea(heights) << endl;
    return 0;
}
