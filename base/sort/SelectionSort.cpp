#include <iostream>
using namespace std;

void selection_sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        //首先将最小值假设为0
        int min = i;
        //在当前元素的后面所有元素中寻找最小的元素
        for (int j = i + 1; j < len; j++)
            if (arr[j] < arr[min])
                min = j;
        //找到最小元素后将其与当前元素交换位置
        swap(arr[i], arr[min]);
    }
}

int main()
{
    int arr[] = {61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sort:\t";
    for (auto a : arr)
        cout << a << " ";
    selection_sort(arr, len);
    cout << endl
         << "After sort:\t";
    for (auto a : arr)
        cout << a << " ";
    return 0;
}