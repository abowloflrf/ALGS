#include <iostream>
using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        if (n < 1) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        int n1 = 1;
        int n2 = 2;
        for (int i = 3; i < n; i++) {
            int tmp = n1;
            n1 = n2;
            n2 = n1 + tmp;
        }
        return n1 + n2;
    }
};

int main(int argc, char const *argv[]) {
    if (argc > 1) {
        int n = atoi(argv[1]);
        Solution s;
        cout << s.climbStairs(n) << endl;
    }
    return 0;
}
