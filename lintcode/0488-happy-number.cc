/**
 * 对于一个正整数，每一次将该数替换为他每个位置上的数字的平方和
 * 然后重复这个过程直到这个数变为1，或是无限循环但始终变不到1
 * 如果可以变为1，返回true
 * 19=>1^2+9^2 (82)=>8^2+2^2 (68)=>6^2+8^2 (100)=> 1
 */
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
   public:
    bool isHappy(int n) {
        int target = n;
        int sum = target;
        unordered_set<int> record = {target};
        while (target != 1) {
            int i = 1;
            sum = 0;
            while (target) {
                i = target % 10;
                sum += i * i;
                target /= 10;
            }
            if (record.count(sum)) return false;
            record.insert(sum);
            target = sum;
        }
        return true;
    }
};

int main() {
    int number = 2;
    Solution s = Solution();
    bool res = s.isHappy(number);
    return 0;
}