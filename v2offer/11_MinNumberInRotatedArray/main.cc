#include <iostream>
#include <vector>

using namespace std;

int searchMin(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    //只要是旋转排序的数组，则左边一定不小于右边的数
    //否则这就是一个顺序排列的数组，直接返回最左边即可
    while (arr[left] >= arr[right]) {
        //只有左右两个元素直接返回
        if (right - left == 1) return arr[right];

        int mid = left + (right - left) / 2;

        //最左与最右与中间数均相等，这时无法判断最小值在左边还是右边部分
        //因此直接顺序遍历找最小值
        if (arr[left] == arr[right] && arr[left] == arr[mid]) {
            int minNumber = arr[left];
            for (int i = left + 1; i <= right; i++)
                if (arr[i] < minNumber) minNumber = arr[i];
            return minNumber;
        }
        //中间值大于最左数，则最小值在右半部分
        if (arr[mid] >= arr[left]) left = mid;
        //中间值小于最左数，则最小值在左半部分
        else if (arr[mid] <= arr[right])
            right = mid;
    }
    return arr[left];
}

int main() {
    vector<int> vec = {1, 2, 3, 0};
    int minNumber = searchMin(vec);
    cout << minNumber << endl;
    return 0;
}