//
// Created by ruofeng on 2018/7/24.
//

#include <string>
#include <unordered_map>
#include <iostream>
#include <cstring>

using namespace std;

// 不需要使用hash表，其实一个128长度的数组就能记录
//int getFirst(string str) {
//    unordered_map<char, int> charMap;
//    int len = str.length();
//    for (int i = 0; i < len; i++) {
//        auto iter = charMap.find(str[i]);
//        if (iter != charMap.end())
//            charMap.erase(iter);
//        else
//            charMap.insert({str[i], 1});
//    }
//    for (int j = 0; j < len; j++) {
//        if (charMap.find(str[j]) != charMap.end() && charMap[str[j]] == 1)
//            return j;
//    }
//    return -1;
//}

int getFirst(string s) {
    int charMap[128]={0};
    int len = s.length();
    for (int i = 0; i < len; i++) {
        charMap[s[i]]++;
    }
    for (int j = 0; j < len; j++) {
        if (charMap[s[j]] == 1)
            return j;
    }
    return -1;
}

int main() {
    string str = "loveyoutandleetcode";
    cout << getFirst(str) << endl;
    return 0;
}