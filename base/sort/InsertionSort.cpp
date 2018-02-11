#include <iostream>
using namespace std;

void insertion_sort(int arr[], int len)
{
    int i, j, temp;

    for (i = 1; i < len; i++)
    {
        temp = arr[i];

        for (j = i; j > 0 && arr[j - 1] > temp; j--)
        {
            arr[j] = arr[j - 1];
        }

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