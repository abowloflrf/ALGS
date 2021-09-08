class Solution {
  public:
    int sumNums(int n) {
        /**
         * 关键：不能使用乘除，因此只能递归
         */
        if (n == 1)
            return 1;
        return sumNums(n - 1) + n;
    }
};