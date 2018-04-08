class Solution {
   public:
    bool isPalindrome(int x) {
        int a = x;
        // int64 避免在取反向数时溢出
        long long r = 0;

        //负数不能为回文数
        if (x < 0) return false;
        //与007相同，直接遍历反向
        while (a > 0) {
            r = r * 10 + a % 10;
            a = a / 10;
        }
        //若反向与原输入数据相等则为回文数
        return r == x;
    }
};