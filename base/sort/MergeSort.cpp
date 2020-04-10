#include <iostream>
#include <vector>

using namespace std;

//合并arr的两个子数组，arr[l...m]与arr[m+1...r]
void merge(int arr[], int l, int m, int r) {
    //计算左右数组长度
    int left_len = m - l + 1;
    int right_len = r - m;

    //为左右两个子数组建立临时数组
    int arr_l[left_len];
    int arr_r[right_len];
    for (int i = 0; i < left_len; i++)
        arr_l[i] = arr[l + i];
    for (int i = 0; i < right_len; i++)
        arr_r[i] = arr[m + 1 + i];

    //初始化左右数组的索引为0，以及目标数组的索引为l
    int i = 0;
    int j = 0;
    int k = l;

    //开始合并两个子数组
    while (i < left_len && j < right_len) {
        //两个子数组从左向右开始比较，小的移到目标数组
        if (arr_l[i] <= arr_r[j]) {
            arr[k] = arr_l[i];
            i++;
        } else {
            arr[k] = arr_r[j];
            j++;
        }
        k++;
    }
    //将子数组中剩余的元素移到目标数组
    while (i < left_len) {
        arr[k] = arr_l[i];
        i++;
        k++;
    }
    while (j < right_len) {
        arr[k] = arr_r[j];
        j++;
        k++;
    }
}
//要排序的为目标数组arr以l为左索引，r为右索引的子数组
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        //计算m为l、r中间索引
        int m = l + (r - l) / 2;
        //合并前一半
        merge_sort(arr, l, m);
        //合并后一半
        merge_sort(arr, m + 1, r);
        //执行比较并合并
        merge(arr, l, m, r);
    }
}

// Merge 为合并两个已经排序的数组
void Merge(vector<int> &nums, int left, int mid, int right) {
    //为左右两个子数组建立临时数组
    vector<int> leftArr(nums.begin() + left, nums.begin() + mid + 1);
    vector<int> rightArr(nums.begin() + mid + 1, nums.begin() + right + 1);
    int idxLeft = 0, idxRight = 0;
    leftArr.insert(leftArr.end(), numeric_limits<int>::max());
    rightArr.insert(rightArr.end(), numeric_limits<int>::max());

    for (int i = left; i <= right; i++) {
        if (leftArr[idxLeft] < rightArr[idxRight]) {
            nums[i] = leftArr[idxLeft];
            idxLeft++;
        } else {
            nums[i] = rightArr[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(vector<int> &nums, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);
    Merge(nums, left, mid, right);
}

int main() {
    int arr[] = {61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sort:\t";
    for (auto a : arr)
        cout << a << " ";
    merge_sort(arr, 0, len - 1);
    cout << endl << "After sort:\t";
    for (auto a : arr)
        cout << a << " ";
    return 0;
}
