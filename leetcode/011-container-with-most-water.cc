//
// Created by ruofeng on 2018/7/29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while (left < right) {
            // h为可储存水的高度，左右两边小的一边
            int h = min(height[right], height[left]);
            res = max(res, h * (right - left));
            // 若两边的长度比比h小，则向中间找到较大的
            // 因为若向中间靠拢，宽度必然更小，只有找到更高的短边才有可能使得容量比之前大
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
