#include <vector>
using namespace std;

// min of rotated array
// [3,4,5,1,2] -> 1
class Solution {
  public:
    int minArray(vector<int> &numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            // 若找到最小值直接return：mid < mid-1
            if (mid > 0 && numbers[mid] < numbers[mid - 1])
                return numbers[mid];

            if (numbers[mid] > numbers[right]) {
                // mid>right 说明存在 rotate，且最小的结果在右边
                left = mid + 1;
            } else if (numbers[mid] < numbers[right]) {
                // mid>right 不一定有 rotate，可能块都是线性递增、或有 rorate
                // 但最小结果位置一定<=mid
                right = mid;
            } else {
                // mid 若和 right 相等，无法判断是在左边还是右边，直接线性遍历
                int minN = __INT32_MAX__;
                for (int i = left; i <= right; i++) {
                    if (numbers[i] < minN)
                        minN = numbers[i];
                }
                return minN;
            }
        }
        return numbers[left];
    }
};

int main(int argc, char const *argv[]) {
    vector<int> data = {3, 3, 1, 3};
    Solution s;
    int m = s.minArray(data);
    return 0;
}
