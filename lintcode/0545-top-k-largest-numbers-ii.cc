#include <set>
#include <vector>
using namespace std;

class Solution {
   private:
    multiset<int> topKSet;
    int K;

   public:
    /*
     * @param k: An integer
     */
    Solution(int k) {
        this->K = k;
        for (int i = 0; i < k; i++) this->topKSet.insert(0);
        // do intialization if necessary
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        if (topKSet.size() < this->K)
            this->topKSet.insert(num);
        else {
            if (num > *(this->topKSet.begin())) {
                this->topKSet.erase(this->topKSet.begin());
                this->topKSet.insert(num);
            }
        }
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here
        int resSize = this->K;
        if (this->topKSet.size() < this->K) resSize = this->topKSet.size();

        vector<int> res(resSize);
        for (int i : this->topKSet) res[--resSize] = i;
        return res;
    }
};