#include <queue>

using namespace std;

class Solution {
  public:
    Solution() {
        cnt = 0;
    }
    vector<double> median(vector<int> &nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            addNumber(nums[i]);
            ans.push_back(getMedian());
        }
        return ans;
    }
    void addNumber(int value) {
        //小根堆储存大的一半数
        //大根堆储存小的一半数

        if (cnt&1 == 0) {
            // 当前元素个数是偶数时，新加入的元素进入小根堆
            // 新元素先加入大根堆，然后经过大根堆筛选后将大根堆中的最大元素进入小根堆
            maxHeap.push(value);
            //将大根堆的最大元素加入到小根堆
            minHeap.push(maxHeap.top());
            //删除大根堆的堆顶
            maxHeap.pop();
        } else {
            // 当前元素个数为奇数时，新加入的元素进入大根堆
            // 新元素先加入小根堆，然后经过小根堆筛选后将小根堆中的最小元素进入大根堆
            minHeap.push(value);
            // 将小根堆中的最小元素加入到大根堆
            maxHeap.push(minHeap.top());
            // 删除小根堆的最小元素
            minHeap.pop();
        }

        cnt++;

    }
    //直接获取中位数
    double getMedian() {
        if (cnt & 1)
            return (double) minHeap.top();
        else
            return (double) (maxHeap.top() + minHeap.top()) / 2;

    }
  private:
    priority_queue<int, vector<int>, less<>> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
    vector<double> ans;
    int cnt;
};

int main() {
    vector<int> data = {2, 20, 13, 18, 15, 8, 3, 5, 4, 25};
    Solution s;
    vector<double> res = s.median(data);
    return 0;
}