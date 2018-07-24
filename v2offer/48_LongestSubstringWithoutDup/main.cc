//
// Created by ruofeng on 2018/7/24.
//

#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int longestSubstring(string str) {
    //用一个数组记录上次该字母的位置，未出现记录为-1
    int position[128];  //记录ASCII码表的所有字符，共128个
    memset(position, -1, sizeof(int) * 128);
    int length = str.length();
    int maxLength = 0;  //记录所有最大长度
    int currentMax = 0; //以i位置的字符结束能得到最长的不重复字符串长度
    for (int i = 0; i < length; i++) {
        //这个字符上次出现的位置
        int prevIndex = position[str[i]];
        //当前字符在前面没有出现过，或出现的位置在当前最大长度之前
        if (prevIndex == -1 || i - prevIndex > currentMax)
            //最大不重复长度直接加一
            currentMax++;
        else {
            if (currentMax > maxLength)
                maxLength = currentMax;
            currentMax = i - prevIndex;
        }
        position[str[i]] = i;

    }
    if (currentMax > maxLength)
        maxLength = currentMax;
    return maxLength;
}

int main() {
    string str = "arabcacfrpocrf";//acfrpo
    int res = longestSubstring(str);
    cout << res << endl;
    return 0;
}
