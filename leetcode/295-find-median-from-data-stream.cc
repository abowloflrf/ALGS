/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (39.27%)
 * Likes:    2023
 * Dislikes: 38
 * Total Accepted:    167.5K
 * Total Submissions: 403.6K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * For example,
 *
 * [2,3,4], the median is 3
 *
 * [2,3], the median is (2 + 3) / 2 = 2.5
 *
 * Design a data structure that supports the following two operations:
 *
 *
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 *
 *
 *
 *
 * Example:
 *
 *
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3)
 * findMedian() -> 2
 *
 *
 *
 *
 * Follow up:
 *
 *
 * If all integer numbers from the stream are between 0 and 100, how would you
 * optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how
 * would you optimize it?
 *
 *
 */
#include <list>
#include <queue>
using namespace std;

// 插入排序的方式
// 添加数字 O(n)
// 获得中位数 O(n)
class MedianFinder1 {
  public:
    /** initialize your data structure here. */
    MedianFinder1() { data = {}; }

    void addNum(int num) {
        if (data.empty() || data.back() <= num) {
            data.push_back(num);
            return;
        }

        for (auto it = data.begin(); it != data.end(); it++) {
            if (*it < num)
                continue;
            data.insert(it, num);
            break;
        }
    }

    double findMedian() {
        list<int>::iterator it = data.begin();
        for (int i = 0; i < data.size() / 2; i++) {
            it++;
        }
        if (data.size() % 2 == 0) {
            int current = *it;
            it--;
            int before = *it;
            return (double(current) + double(before)) / 2;
        }
        return *it;
    }

  private:
    list<int> data;
};

// @lc code=start

// 大小堆分别放大的一半和小的一半
// 每次插入需要保持大小堆的size平衡，一样或相差1
class MedianFinder {
  public:
    /** initialize your data structure here. */
    MedianFinder() {
        greaterPart = {};
        lessPart = {};
    }

    void addNum(int num) {
        // 策略为保持 小的一部分size始终>=大的一部分size
        lessPart.push(num);
        greaterPart.push(lessPart.top());
        lessPart.pop();

        if (lessPart.size() < greaterPart.size()) {
            lessPart.push(greaterPart.top());
            greaterPart.pop();
        }
    }

    double findMedian() {
        if (lessPart.size() > greaterPart.size())
            return lessPart.top();
        return (double(lessPart.top()) + double(greaterPart.top())) / 2;
    }

  private:
    priority_queue<int, vector<int>, greater<int>> greaterPart;
    priority_queue<int, vector<int>, less<int>> lessPart;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
int main() {
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    double a = m.findMedian();
    return 0;
}