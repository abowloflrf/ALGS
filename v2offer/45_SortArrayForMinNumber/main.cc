//
// Created by ruofeng on 2018/7/24.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

//自定义的比较函数是关键
bool compare(string str1, string str2) {
    string s1 = str1 + str2;
    string s2 = str2 + str1;
    return s1 < s2;
}

string getMinNumber(vector<int> arr) {
    //首先需要将数字数组转为字符串数组
    vector<string> strArr;
    char buff[100];
    for (int i = 0; i < arr.size(); i++) {
        sprintf(buff, "%d", arr[i]);
        strArr.push_back(string(buff));
    }
    //对字符串数组进行排序
    sort(strArr.begin(), strArr.end(), compare);
    //依次拼接字符串并返回
    string res;
    for (auto s:strArr) {
        res += s;
    }
    return res;
}

int main() {
    vector<int> numbers = {3, 32, 321, 9};
    cout << getMinNumber(numbers) << endl;
    return 0;
}