#include <iostream>
using namespace std;
void bubble_sort(int arr[], int len)
{
    int i, j;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
int main()
{
    int arr[] = {61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Before sort:\t";
    for (auto a : arr)
        cout << a << " ";
    bubble_sort(arr, len);
    cout << endl
         << "After sort:\t";
    for (auto a : arr)
        cout << a << " ";
    return 0;
}