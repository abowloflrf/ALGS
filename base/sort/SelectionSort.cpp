#include <iostream>
using namespace std;

void selection_sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
            if (arr[j] < arr[min])
                min = j;
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