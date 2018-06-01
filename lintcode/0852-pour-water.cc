#include <vector>
using namespace std;
class Solution {
   public:
    /**
     * @param heights: the height of the terrain
     * @param V: the units of water
     * @param K: the index
     * @return: how much water is at each index
     */
    vector<int> pourWater(vector<int> &heights, int V, int K) {
        int size = heights.size();
        while (V--) {
            int targetIndex = -1;  //初始化要插入的目标地址
            //向左计算
            int left = K - 1;
            while (left >= 0 && heights[left] <= heights[left + 1]) {
                //关键：检查是否全水平，是全水平则原地增加，不改变targetIndex
                if (heights[left] < heights[left + 1]) targetIndex = left;
                left--;
            }
            //否则表明没有进入while循环（左边更高）或while中的每次比较都是相等（左边水平），进入向右边的计算
            if (targetIndex != -1) {
                heights[targetIndex]++;
                continue;
            }
            //向右计算（与上面同理）
            int right = K + 1;
            while (right < size && heights[right] <= heights[right - 1]) {
                if (heights[right] < heights[right - 1]) targetIndex = right;
                right++;
            }
            if (targetIndex != -1) {
                heights[targetIndex]++;
                continue;
            }
            //两边都不满足下落条件，则保留在原地
            heights[K]++;
        }
        return heights;
    }
};

int main() {
    Solution s = Solution();
    vector<int> heights = {13, 7, 9, 6, 4, 4, 4, 10, 15, 9};
    vector<int> res;
    res = s.pourWater(heights, 7, 1);
    return 0;
}