//
// Created by ruofeng on 2018/7/17.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<string> permutaion(string str) {
        vector<string> result;
        permutationCore(str, 0, result);
        return result;
    }
  private:
    void permutationCore(string &str, int index, vector<string> &result) {
        if (index == str.size()) {
            result.push_back(str);
        } else {
            for (int i = index; i < str.size(); i++) {
                swap(str[i], str[index]);
                permutationCore(str, index + 1, result);
                swap(str[i], str[index]);
            }
        }

    }
};

int main() {
    Solution s;
    string str = "123";
    vector<string> res = s.permutaion(str);
    for (auto i:res)
        cout << i << endl;
    return 0;
}