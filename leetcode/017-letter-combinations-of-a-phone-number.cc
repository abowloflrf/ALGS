//
// Created by ruofeng on 2018/7/30.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<vector<char>> numberMap = {
            {},                     //0
            {},                     //1
            {'a', 'b', 'c'},        //2
            {'d', 'e', 'f'},        //3
            {'g', 'h', 'i'},        //4
            {'j', 'k', 'l'},        //5
            {'m', 'n', 'o'},        //6
            {'p', 'q', 'r', 's'},   //7
            {'t', 'u', 'v'},        //8
            {'w', 'x', 'y', 'z'}    //9
        };
        //全排列
        vector<string> res;
        res.push_back("");
        for (int i = 0; i < digits.length(); i++) {
            vector<string> tmp;
            vector<char> chars = numberMap[digits[i] - '0'];
            for (int c = 0; c < chars.size(); c++)
                for (int j = 0; j < res.size(); j++)
                    tmp.push_back(res[j] + chars[c]);
            res = tmp;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> r = s.letterCombinations("23");
    for (auto i:r)
        cout << i << endl;
    return 0;
}