#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   private:
    unordered_set<char> root;
    unordered_map<string, unordered_set<char>> mMap;

    void search(string bottom) {
        if (bottom.size() == 2) {
            if (mMap.count(bottom))
                for (char c : mMap[bottom]) root.insert(c);
        } else {
            vector<string> res = getBottomTop(bottom);
            for (auto line : res) {
                if (line.empty())
                    return;
                else
                    search(line);
            }
        }
    }

    vector<string> getBottomTop(string bottom) {
        int size = bottom.size();  // bottom层长度
        int topLen = size - 1;     //上一层长度
        vector<vector<char>> cands(topLen);  //保存上一层每一位可能的字符组合

        //这里已经是size大于2的情况
        for (int i = 0; i < topLen; i++) {
            string pair = bottom.substr(i, 2);
            if (!mMap.count(pair))
                //只要有一组没有结果直接返回空vector
                return {};
            else {
                for (char c : mMap[pair]) cands[i].push_back(c);
            }
        }
        //组合成所有可能的上一层
        int num = 1;
        for (int i = 0; i < topLen; i++) {
            num *= cands[i].size();
        }
        vector<string> res(num);
        for (auto s : cands) {
            for (int i = 0; i < num; i++) {
                res[i] += s[i % s.size()];
            }
        }
        return res;
    }

   public:
    unordered_set<char> getRoot(
        string bottom, unordered_map<string, unordered_set<char>> statusMap) {
        mMap = statusMap;
        search(bottom);
        return root;
    }
};

int main() {
    string btm = "ABCC";
    unordered_map<string, unordered_set<char>> statusMap;
    statusMap["AA"] = {'B'};
    statusMap["AB"] = {'A', 'C'};
    statusMap["AC"] = {'D'};
    statusMap["AD"] = {'A'};
    statusMap["BA"] = {'D'};
    statusMap["BB"] = {'B', 'C'};
    statusMap["BC"] = {'A'};
    statusMap["CC"] = {'B'};
    Solution s;
    unordered_set<char> result = s.getRoot(btm, statusMap);
    return 0;
}