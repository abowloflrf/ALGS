/**
 * 1. 排序，双向指针夹闭
 * 2. hash
 */

#include <unordered_map>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) m[nums[i]] = i;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        auto iter = m.find(target - nums[i]);
        if (iter != m.end() && iter->second > i) {
            result.push_back(i);
            result.push_back(iter->second);
            break;
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    vector<int> v1 = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(v1, target);
    return 0;
}
