//最长不重复字串

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        //用一个数组记录上次该字母的位置，未出现记录为-1
        int position[128];
        memset(position, -1, sizeof(int) * 128);
        int length = s.length();
        int maxLength = 0;  //记录所有最大长度
        int currentMax = 0;  //以i位置的字符结束能得到最长的不重复字符串长度
        for (int i = 0; i < length; i++) {
            //这个字符上次出现的位置
            int prevIndex = position[s[i]];
            //当前字符在前面没有出现过，或出现的位置在当前最大长度之前
            if (prevIndex == -1 || i - prevIndex > currentMax)
                //最大不重复长度直接加一
                currentMax++;
            else {
                //保存到这里能够得到的最大长度
                if (currentMax > maxLength) maxLength = currentMax;
                //重新计算
                currentMax = i - prevIndex;
            }
            //保存本次字符出现的位置
            position[s[i]] = i;
        }
        if (currentMax > maxLength) maxLength = currentMax;
        return maxLength;
    }
};

int main() {
    Solution s;
    string str = "abccba";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}