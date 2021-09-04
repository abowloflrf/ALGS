#include <algorithm>
using namespace std;
class Solution {
  public:
    /**
     * dp[i]
     */
    int cuttingRope(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            int m = i; // j=0时，不切取本身长度
            for (int j = 1; j < i; j++) {
                m = max(m, j * dp[i - j]);
            }
            dp[i] = m;
        }

        return dp[n];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    s.cuttingRope(6);
    return 0;
}
