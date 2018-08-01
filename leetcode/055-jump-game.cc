//
// Created by ruofeng on 2018/8/1.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int lastPos = nums.size() - 1;
        for (int i = lastPos; i >= 0; i--) {
            if (i + nums[i] >= lastPos)
                lastPos = i;
        }
        return lastPos == 0;
    }
};