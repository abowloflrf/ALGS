#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int min = prices[0];
        int maxP = prices[1] - prices[0];
        for (int i = 2; i < prices.size(); i++) {
            if (prices[i - 1] < min) min = prices[i - 1];
            int curr = prices[i] - min;
            if (curr > maxP) maxP = curr;
        }

        return maxP < 0 ? 0 : maxP;
    }
};