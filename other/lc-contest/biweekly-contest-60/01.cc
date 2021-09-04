#include <vector>
using namespace std;

class Solution {
  public:
    int findMiddleIndex(vector<int> &nums) {
        if (nums.size() == 1)
            return 0;

        int middleIdx = 0;
        int leftSum = 0;
        int rightSum = 0;
        for (int n : nums) {
            rightSum += n;
        }
        rightSum -= nums[0];
        if (leftSum == rightSum)
            return 0;

        for (int i = 1; i < nums.size(); i++) {
            leftSum += nums[i - 1];
            rightSum -= nums[i];
            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {

    vector<int> v = {2};
    Solution s;
    int a = s.findMiddleIndex(v);
    return 0;
}
