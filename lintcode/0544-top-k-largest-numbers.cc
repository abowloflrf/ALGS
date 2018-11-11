#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        int size = nums.size();
        multiset<int> topK;
        for (int i = 0; i < k; i++) topK.insert(nums[i]);
        for (int j = k; j < size; j++) {
            if (nums[j] > *(topK.begin())) {
                topK.erase(topK.begin());
                topK.insert(nums[j]);
            }
        }

        vector<int> res(k);
        for (auto i : topK) {
            res[--k]=i;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> in = {3,10,1000,-99,4,100};
    Solution s;
    vector<int> r = s.topk(in, 3);
    return 0;
}
