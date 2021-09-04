#include <vector>
using namespace std;

class Solution {
  private:
    vector<vector<int>> ans;

    void mark(int x, int y, vector<vector<int>> &land) {
        int width = 0;
        int height = 0;
        // 计算宽度
        for (int i = x; i < land.front().size(); i++) {
            if (land[y][i] == 1) {
                width++;
            } else {
                break;
            }
        }
        // 计算高度
        for (int i = y; i < land.size(); i++) {
            if (land[i][x] == 1) {
                height++;
            } else {
                break;
            }
        }
        // 走过的农场全部标记为 -1
        for (int i = x; i < x + width; i++) {
            for (int j = y; j < y + height; j++) {
                land[j][i] = -1;
            }
        }
        ans.push_back({y, x, y + height - 1, x + width - 1});
    }

  public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land) {
        int width = land.front().size();
        int height = land.size();
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                if (land[y][x] == 1)
                    mark(x, y, land);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> i = {{1, 1}, {0, 0}};
    Solution s;
    auto a = s.findFarmland(i);
    return 0;
}
