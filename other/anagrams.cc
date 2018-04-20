/**
 * 给出一份字典包含若干个英文单词，要求按照这样的规则将这份单词分组：
 * 单词出现的字母相同且每个字母出现的次数相同分为一组，例如cat/act
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, vector<string>> solution(vector<string> data) {
    unordered_map<string, vector<string>> result;
    for (auto i : data) {
        string temp = i;
        sort(i.begin(), i.end());
        result[i].push_back(temp);
    }
    return result;
}

int main() {
    vector<string> data = {"act", "ate",    "tea",     "buffer",
                           "cat", "string", "anagram", "nagaram"};
    unordered_map<string, vector<string>> ret = solution(data);

    return 0;
}