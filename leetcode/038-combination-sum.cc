//
// Created by ruofeng on 2018/8/1.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> conbination;
        combinationSum(candidates, target, res, conbination, 0);
        return res;
    }
  private:
    void combinationSum(vector<int> &candidates,
                        int target,
                        vector<vector<int>> &res,
                        vector<int> &combination,
                        int begin) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        //回溯
        for (int i = begin; i != candidates.size() && target >= candidates[i]; i++) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }

};

int main() {

}