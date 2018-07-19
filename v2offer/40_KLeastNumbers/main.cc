#include <iostream>
#include <set>
#include <vector>

using namespace std;

int partition(vector<int>& numbers, int start, int end) {
    int target = numbers[end];

    int left = start;
    int right = end - 1;

    while (left < right) {
        while (numbers[left] < target && left < right) left++;
        while (numbers[right] >= target && left < right) right--;
        swap(numbers[left], numbers[right]);
    }
    if (numbers[left] >= numbers[end])
        swap(numbers[left], numbers[end]);
    else
        left++;
    return left;
}

vector<int> getLeastK_1(vector<int> data, int k) {
    if (data.size() == 0 || k > data.size()) return {};
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

vector<int> getLeastK_2(vector<int> data, int k) {
    if (data.size() <= k) return data;

    multiset<int, greater<int>> kSet;
    vector<int>::iterator iter = data.begin();
    for (; iter != data.end(); iter++) {
        if (kSet.size() < k)
            kSet.insert(*iter);
        else {
            multiset<int, greater<int>>::iterator maxInSet = kSet.begin();
            if (*iter < *maxInSet) {
                kSet.erase(maxInSet);
                kSet.insert(*iter);
            }
        }
    }
    vector<int> result;
    for (auto i : kSet) result.push_back(i);
    return result;
}

int main() {
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8, 9, 11};
    vector<int> leastK = getLeastK_1(data, 5);
    for (auto i : leastK) cout << i << "-";
    return 0;
}