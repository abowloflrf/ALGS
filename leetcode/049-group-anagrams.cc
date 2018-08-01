//
// Created by ruofeng on 2018/8/1.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> resMap;
        for (auto str:strs) {
            string tmpStr = str;
            sort(tmpStr.begin(), tmpStr.end());
            resMap[tmpStr].push_back(str);
        }
        for (auto v: resMap)
            res.push_back(v.second);
        return res;
    }
};

int main() {
    vector<string> data = {"act", "ate", "tea", "buffer",
                           "cat", "string", "anagram", "nagaram"};
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(data);
    return 0;
}