#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    // 超时
    int circleGame(vector<vector<int>> &toys, vector<vector<int>> &circles, int r) {
        unordered_set<int> complete;
        for (auto c : circles) {
            for (int i = 0; i < toys.size(); i++) {
                if (complete.count(i) < 1) {
                    if (valid(toys[i], c, r)) {
                        complete.insert(i);
                        if (complete.size() == toys.size()) {
                            return toys.size();
                        }
                    }
                }
            }
        }
        return complete.size();
    }

  private:
    bool valid(vector<int> &toy, vector<int> &circle, int r) {
        if (toy[2] > r)
            return false;
        int x = abs(toy[0] - circle[0]);
        int y = abs(toy[1] - circle[1]);
        return (r - toy[2]) * (r - toy[2]) >= (x * x + y * y);
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> toys = {{3, 4, 5}, {1, 4, 4}, {4, 4, 1}, {1, 5, 5}};
    vector<vector<int>> circles = {{4, 1}, {4, 2}};
    int a = s.circleGame(toys, circles, 6);
    /**
     * [[3,4,5],[1,4,4],[4,4,1],[1,5,5]]
     * [[4,1],[4,2]]
     * 6
     *
     */
    return 0;
}
