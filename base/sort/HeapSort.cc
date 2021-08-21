#include <iostream>
#include <vector>

using namespace std;

//构建堆的过程时间复杂度为O(n)
void maxHeapify(vector<int>& data, int i, int n) {
    // 得到 i 的左右的子节点索引
    int indexMax = i, indexLeft = 2 * i + 1, indexRight = 2 * (i + 1);

    // 得到左右哪个值最大
    if (indexLeft < n && data[i] < data[indexLeft]) {
        indexMax = indexLeft;
    }
    if (indexRight < n && data[indexMax] < data[indexRight]) {
        indexMax = indexRight;
    }

    // 若左右有大于根节点的则作交换并递归调用
    if (indexMax != i) {
        swap(data[indexMax], data[i]);
        maxHeapify(data, indexMax, n);
    }
}

//堆排序的时间复杂度为O(nlogn)
void heapSort(vector<int>& data) {
    // 从顶部开始构建堆
    int heapSize = data.size();
    for (int i = heapSize / 2 - 1; i >= 0; i--) maxHeapify(data, i, heapSize);

    for (int i = heapSize - 1; i >= 0; i--) {
        //首尾交换，断尾重建堆，每次将大根堆的顶部放到最后然后i--表示重建时不管最后一个元素看
        //因为它已经是整个数组中最大的元素
        swap(data[0], data[i]);
        maxHeapify(data, 0, i);
    }
}

int main(int argc, char const* argv[]) {
    vector<int> data = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    heapSort(data);
    for (auto i : data) {
        cout << i << "-";
    }
    return 0;
}
