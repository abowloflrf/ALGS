#include <iostream>
#include <set>
#include <vector>

using namespace std;

// 每次取数组最后一个数作为目标，比它小的排左边，比它小的排右边
int partition(vector<int> &numbers, int start, int end) {
    int target = numbers[end];

    int left = start;
    int right = end - 1;

    while (left < right) {
        while (numbers[left] < target && left < right)
            left++;
        while (numbers[right] >= target && left < right)
            right--;
        swap(numbers[left], numbers[right]);
    }
    if (numbers[left] >= numbers[end])
        swap(numbers[left], numbers[end]);
    else
        left++;
    return left;
}

// 快速排序思路
vector<int> getLeastK_1(vector<int> data, int k) {
    if (data.size() == 0 || k > data.size())
        return {};
    int start = 0;
    int end = data.size() - 1;
    int index = partition(data, start, end);
    while (index != k - 1) {
        if (index > k - 1) {
            //在右边
            end = index - 1;
            index = partition(data, start, end);
        } else {
            //在左边
            start = index + 1;
            index = partition(data, start, end);
        }
    }
    return vector<int>(data.begin(), data.begin() + k);
}

// 使用堆
vector<int> getLeastK_2(vector<int> arr, int k) {
    if (arr.size() <= k)
        return arr;

    multiset<int, greater<int>> kSet;
    for (int i = 0; i < arr.size(); i++) {
        if (kSet.size() < k)
            // multiset 容量未到k，直接插入
            kSet.insert(arr[i]);
        else {
            // multiset容量超过k，删除最大的
            // set中，begin最大，end最小
            auto maxInSet = kSet.begin();
            if (arr[i] < *maxInSet) {
                kSet.erase(maxInSet);
                kSet.insert(arr[i]);
            }
        }
    }
    vector<int> result;
    for (auto i : kSet)
        result.push_back(i);
    return result;
}

int main() {
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8, 9, 11};
    vector<int> leastK = getLeastK_2(data, 5);
    for (auto i : leastK)
        cout << i << "-";
    return 0;
}