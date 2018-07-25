//
// Created by ruofeng on 2018/7/25.
//

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    void inQueue(deque<int> &Q, int num) {
        //将Q末尾小于目标数的元素全部出队，再入队（关键操作）
        while (!Q.empty() && Q.back() < num) {
            Q.pop_back();
        }
        Q.push_back(num);
    }
    void outQueue(deque<int> &Q, int num) {
        //队列头部与目标数相等时出队
        if (Q.front() == num)
            Q.pop_front();
    }
  public:
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
        deque<int> Q;
        vector<int> result;
        //先入队k-1个数，还未到第一个窗口
        for (int i = 0; i < k - 1; i++) {
            inQueue(Q, nums[i]);
        }
        //再从第k个数（第一个窗口）开始向后判断，每次循环中得到该窗口的最大值并加入到结果数组中
        for (int j = k - 1; j < nums.size(); ++j) {
            //每次先入队，若上次最后一个失效的元素被移除，这里会有新的元素进入
            inQueue(Q, nums[j]);
            //队列首部时钟保存着这个窗口的最大值
            result.push_back(Q.front());
            //然后将窗口经过刚刚失效的那一位数字出队（若存在）
            outQueue(Q, nums[j - k + 1]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> res = s.maxSlidingWindow({4, 2, 9, 5, 8, 4, 7, 5, 1}, 4);
    for (auto i:res)
        cout << i << "-";
    return 0;
}