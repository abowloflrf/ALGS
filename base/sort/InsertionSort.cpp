#include <iostream>
using namespace std;

void insertion_sort(int arr[], int len)
{
    int i, j, temp;

    for (i = 1; i < len; i++)
    {
        //要插入的目标存入temp中
        temp = arr[i];
        //从目标元素位置向前比较，若前面的元素较大则将其移到后一位
        //直到找到前面比目标元素小的元素或者到头
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
        {
            arr[j] = arr[j - 1];
        }
        //将目标元素保存到上一个向后移动位置的元素位置
        arr[j] = temp;
    }
}

int main()
{
    int arr[] = {61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sort:\t";
    for (auto a : arr)
        cout << a << " ";
    insertion_sort(arr, len);
    cout << endl
         << "After sort:\t";
    for (auto a : arr)
        cout << a << " ";
    return 0;
}