/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode-cn.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (52.33%)
 * Likes:    544
 * Dislikes: 0
 * Total Accepted:    62.4K
 * Total Submissions: 119.2K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * The median is the middle value in an ordered integer list. If the size of
 * the list is even, there is no middle value and the median is the mean of the
 * two middle values.
 *
 *
 * For example, for arr = [2,3,4], the median is 3.
 * For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
 *
 *
 * Implement the MedianFinder class:
 *
 *
 * MedianFinder() initializes the MedianFinder object.
 * void addNum(int num) adds the integer num from the data stream to the data
 * structure.
 * double findMedian() returns the median of all elements so far. Answers
 * within 10^-5 of the actual answer will be accepted.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * Output
 * [null, null, null, 1.5, null, 2.0]
 *
 * Explanation
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *
 *
 *
 * Constraints:
 *
 *
 * -10^5 <= num <= 10^5
 * There will be at least one element in the data structure before calling
 * findMedian.
 * At most 5 * 10^4 calls will be made to addNum and findMedian.
 *
 *
 *
 * Follow up:
 *
 *
 * If all integer numbers from the stream are in the range [0, 100], how would
 * you optimize your solution?
 * If 99% of all integer numbers from the stream are in the range [0, 100], how
 * would you optimize your solution?
 *
 *
 */
#include <list>
#include <queue>
using namespace std;
// @lc code=start
class MedianFinder {
  private:
    // 大根堆存小的一半
    priority_queue<int, vector<int>, less<>> maxHeap;
    // 小根堆存大的一半
    priority_queue<int, vector<int>, greater<>> minHeap;

  public:
    MedianFinder() {}

    void addNum(int num) {
        if (minHeap.empty() || num > minHeap.top()) {
            minHeap.push(num);
            if (minHeap.size() - 1 > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        } else {
            maxHeap.push(num);
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }

    double findMedian() {
        if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        return (float(minHeap.top()) + float(maxHeap.top())) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

int main(int argc, char const *argv[]) {
    MedianFinder f;
    float m = 1;
    f.addNum(1);
    f.addNum(2);
    m = f.findMedian();
    f.addNum(3);
    m = f.findMedian();
    f.addNum(5);
    m = f.findMedian();
    return 0;
}

// list 方式，会超时

class MedianFinder2 {
  private:
    list<int> data;

  public:
    /** initialize your data structure here. */
    MedianFinder2() {}

    void addNum(int num) {
        auto target = data.begin();
        for (; target != data.end(); target++) {
            if (num < *target) {
                break;
            }
        }
        data.insert(target, num);
    }

    double findMedian() {
        list<int>::iterator iter = data.begin();
        for (int i = 0; i < data.size() / 2; i++) {
            iter++;
        }
        if (data.size() % 2) {
            return float(*iter);
        } else {
            float curr = *(iter);
            float prev = *(--iter);
            return (curr + prev) / 2;
        }
    }
};