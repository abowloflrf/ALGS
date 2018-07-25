//
// Created by ruofeng on 2018/7/25.
//

#include <string>
#include <iostream>

using namespace std;

string reverseStr(string str) {
    int len = str.length();
    int n = len / 2;
    for (int i = 0; i < n; i++) {
        swap(str[i], str[len - i - 1]);
    }
    return str;
}

int main() {
    string str = "hello world!";
    cout << reverseStr(str) << endl;
    return 0;
}