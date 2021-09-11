
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int minimumSwitchingTimes(vector<vector<int>> &source, vector<vector<int>> &target) {
        unordered_map<int, int> s;
        for (auto i : source) {
            for (int j : i) {
                s[j]++;
            }
        }
        // int sourceN = 0; // source 不满足
        int targetN = 0; // targer 不满足
        // int ans = 0;
        for (auto i : target) {
            for (int j : i) {
                if (s[j] > 0) {
                    s[j]--;
                } else {
                    targetN++;
                }
            }
        }
        // for (auto i : s) {
        //     sourceN += i.second;
        // }
        return targetN;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> source = {{1, 3, 3, 2}, {5, 4, 9, 0}};
    vector<vector<int>> target = {{3, 1, 13, 2}, {5, 4, 4, 4}};
    int ans = s.minimumSwitchingTimes(source, target);
    return 0;
}
