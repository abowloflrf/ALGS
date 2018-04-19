#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

std::vector<int> is_dumplicate_sort(int arr[], int len)
{
    std::sort(arr, arr + len);
    std::vector<int> res;
    for (int i = 1; i < len; i++)
    {
        if (arr[i] == arr[i - 1] && arr[i])
        {
            res.push_back(arr[i]);
        }
    }
    return res;
}

std::vector<int> is_dumplicate_hash(int arr[], int len)
{
    std::unordered_map<int, int> myMap;
    std::vector<int> res;
    for (int i = 0; i < len; i++)
    {
        //map.find(key)==map.end()表示在map中未找到相应key的数据
        if (myMap.find(arr[i]) == myMap.end())
            myMap.insert({i, arr[i]});
        else
        {
            res.push_back(arr[i]);
        }
    }
    return res;
}
std::vector<int> is_dumplicate_swap(int arr[], int len)
{
    std::vector<int> res;

    //参数错误
    if (arr == nullptr || len <= 0)
        return res;
    //无效数据
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < 0 || arr[i] > len - 1)
            return res;
    }
    //开始遍历
    for (int i = 0; i < len; i++)
    {
        //参数与下标不相等
        if (arr[i] != i)
        {
            //寻找此数为下标的数值
            if (arr[i] == arr[arr[i]])
            {
                res.push_back(arr[i]);
            }
            //交换
            std::swap(arr[i], arr[arr[i]]);
        }
    }
    return res;
}
int main()
{
    int arr[] = {3, 1, 8, 5, 7, 3, 6, 4, 5, 0, 3, 9}; //0 1 3 3 3 4 5 5 6 7 8 9
    std::vector<int> res = is_dumplicate_swap(arr, sizeof(arr) / sizeof(arr[0]));
    for (auto v : res)
    {
        std::cout << v << " ";
    }
    return 0;
}