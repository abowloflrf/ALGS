class Solution {
  public:
    int translateNum(int num) { return helper(num, 1); }
    int helper(int num, int count) {
        if (num < 10)
            return count;

        int n = 0, tmp = num;
        n += (tmp % 10);
        tmp /= 10;
        n += 10 * (tmp % 10);
        tmp /= 10;
        if (n >= 26 || n < 10) {
            return helper(num / 10, count);
        } else {
            return helper(num / 10, count) + helper(num / 100, count);
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    int a = s.translateNum(506);
    return 0;
}
