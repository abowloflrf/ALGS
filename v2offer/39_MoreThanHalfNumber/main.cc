#include <iostream>
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

int getNumber(vector<int> numbers) {
    if (numbers.empty()) return -1;
    int length = numbers.size();
    int start = 0;
    int end = length - 1;

    int index = partition(numbers, start, end);
    int middle = length >> 1;
    while (index != middle) {
        //中位数在右边
        if (index > middle) {
            end = index - 1;
            index = partition(numbers, start, end);
        } else {
            start = index + 1;
            index = partition(numbers, start, end);
        }
    }

    int result = numbers[middle];
    // TODO: 检查没有符合条件超过一半的数
    return result;
}

int getNumber_2(vector<int> numbers) {
    int length = numbers.size();

    int target = numbers[0];
    int times = 1;
    for (int i = 0; i < length; i++) {
        if (times == 0) {
            target = numbers[i];
            times = 1;
        } else if (target == numbers[i])
            times++;
        else
            times--;
    }
    return target;
}

int main() {
    vector<int> data = {1, 2, 3, 2, 2, 5, 4, 2};
    int res = getNumber_2(data);
    cout << res << endl;
    return 0;
}