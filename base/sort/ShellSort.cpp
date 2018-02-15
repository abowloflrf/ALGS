#include <iostream>
using namespace std;

template <typename T>
void shell_sort(T arr[], int len)
{
    //首先选择一个步长，按照步长将原数组分组
    int h = len / 2;
    //当步长为1时就可以确保原数组已被全部排序
    while (h > 0)
    {
        for (int i = h; i < len; i++)
            //对每个步长进行插入排序
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h)
                swap(arr[j], arr[j - h]);
        //每个每组都已经排序完毕后，缩小步长
        h = h / 2;
    }
}

int main()
{
    int arr[] = {61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sort:\t";
    for (auto a : arr)
        cout << a << " ";
    shell_sort(arr, len);
    cout << endl
         << "After sort:\t";
    for (auto a : arr)
        cout << a << " ";
    return 0;
}