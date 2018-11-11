#include <vector>
using namespace std;

class Solution {
   public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int currentSize = nums.size();
        if (currentSize == 0) return 0;
        vector<int>::iterator iter = nums.begin();
        while (iter + 1 != nums.end()) {
            if (*(iter + 1) == *iter) {
                currentSize--;
                nums.erase(iter);
                continue;
            }
            iter++;
        }
        return currentSize;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> v = {1, 1, 2, 3, 4, 4, 4, 5, 6, 7};
    Solution s;
    int a = s.removeDuplicates(v);
    return 0;
}
