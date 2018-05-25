#include <iostream>
#include <string>
#include <unordered_map>
class Solution {
   public:
    //在数据较少时使用 switch case 比 hashmap 较好
    int roman(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    int romanToInt(std::string s) {
        std::unordered_map<char, int> flag = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        int len = s.size(), result = 0;
        for (int i = len - 1; i >= 0; i--) {
            //先加第一位
            if (i == len - 1) {
                result += flag[s[i]];
                continue;
            }
            //大于第二位时，若这一位比上一位的数字小则应该相减
            if (flag[s[i]] < flag[s[i + 1]]) {
                result -= flag[s[i]];
            } else {
                result += flag[s[i]];
            }
        }
        return result;
    }
    int romanToInt2(std::string s) {
        int result = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            //先加第一位
            if (i == s.length() - 1) {
                result += roman(s[i]);
                continue;
            }
            //大于第二位时，若这一位比上一位的数字小则应该相减
            if (roman(s[i]) < roman(s[i + 1])) {
                result -= roman(s[i]);
            } else {
                result += roman(s[i]);
            }
        }
        return result;
    }
};