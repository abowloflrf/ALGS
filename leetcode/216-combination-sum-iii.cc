//
// Created by ruofeng on 2018/8/1.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> conbination;
        combinationSum(n, res, conbination, 1, k);
        return res;
    }
  private:
    /**
     *
     * @param target 还需要累加的和
     * @param res 结果数组
     * @param combination 当前累加的数组
     * @param begin 当前推断到的位置
     * @param need 还剩可以加的数的个数
     */
    void combinationSum(int target, vector<vector<int>> &res, vector<int> &combination, int begin, int need) {
        //达到累加目标
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        //剩余0个名额
        if (need == 0)
            return;
        for (int i = begin; i != 10 && target >= i * need + (need - 1) * need / 2; i++) {
            combination.push_back(i);
            combinationSum(target - i, res, combination, i + 1, need - 1);
            //回溯
            combination.pop_back();
        }
    }

};

int main() {

}