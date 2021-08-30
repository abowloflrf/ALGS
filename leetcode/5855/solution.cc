#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string &a, string &b) { return stoi(a) > stoi(b); }
bool cmp2(string &a, string &b) {
    if (a.size() > b.size()) {
        return true;
    }
    if (a.size() < b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i])
            return true;
        if (a[i] < b[i])
            return false;
    }
    return false;
}

class Solution {
  public:
    string kthLargestNumber(vector<string> &nums, int k) {
        // 不能直接转换，可能会溢出，参考大数比较
        sort(nums.begin(), nums.end(), cmp2);
        return nums[k - 1];
    }
};

int main(int argc, char const *argv[]) {

    vector<string> nums = {"21", "2", "12", "982"};
    Solution s;
    s.kthLargestNumber(nums, 2);
    return 0;
}
