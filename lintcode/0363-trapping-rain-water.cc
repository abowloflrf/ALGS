/**
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1. compute how much water it is able to trap after raining.
 * ![Graph](https://lintcode-media.s3.amazonaws.com/problem/rainwatertrap.png)
 *
 * Challage: Time O(n) Space O(1)
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    //参考后的正确答案，左右各定义一个指针向中间前进，两边也同时维护左边最高点和右边最高点
    //在前进的同时将所指向的高度与目前所维护的最高点相比较，并累加
    int trapRainWater(vector<int> &heights) {
        if (heights.empty()) {
            return 0;
        }
        int sum = 0;
        int left = 0;
        int right = heights.size() - 1;
        int maxLeft = 0, maxRight = 0;
        while (left <= right) {
            if (heights[left] <= heights[right]) {  //这个条件有所疑惑
                if (heights[left] < maxLeft) {
                    sum += maxLeft - heights[left];
                } else {
                    maxLeft = heights[left];
                }
                ++left;
            } else {
                if (heights[right] < maxRight) {
                    sum += maxRight - heights[right];
                } else {
                    maxRight = heights[right];
                }
                --right;
            }
        }
        return sum;
    }
    //下面是自己的第一遍思考，答案有误，仅从一边开始使用两个指针向前计算，仅自己记录勿作参考
    int trapRainWater2(vector<int> &heights) {
        if (heights.empty()) return 0;
        vector<int>::const_iterator pa = heights.cbegin();
        vector<int>::const_iterator pb = heights.cbegin();
        int cap = 0;
        while (pa != heights.cend() && pb != heights.cend()) {
            //跳过第一个元素为0的情况
            if (pa == heights.cbegin() && *pa == 0) {
                while (*pa == 0) {
                    pa++;
                    pb++;
                }
                if (pa == heights.cend()) break;
            }
            int heightA = *pa;
            int tempCap = 0;
            pb++;
            while (*pb < heightA && pb != heights.cend()) {
                tempCap += (*pa - *pb);
                pb++;
            }

            if (pb == heights.cend()) {
                pa++;
                pb = pa;
                continue;
            } else {
                pa = pb;
                cap += tempCap;
            }
        }
        return cap;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    // vector<int> vec = {2, 1, 0, 1};
    // vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> vec = {4, 2, 3};
    int res = s.trapRainWater(vec);
    return 0;
}
