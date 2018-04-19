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