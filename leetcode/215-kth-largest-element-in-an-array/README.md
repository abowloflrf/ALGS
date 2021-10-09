# 215. 数组中的第 K 个最大元素

## 小根堆（size=k）

TopK 问题，使用小根堆且维持 size 为 k，大于 k pop 掉堆顶。则该大小为 k 的堆始终为 topK 大小的元素，最终 pop 堆顶即可。

## 大根堆 (size=n)

n 远大于 k 时，该方法使用较多空间

## 排序

## 自己实现最小堆

最小堆需要实现接口

-   `void push(int)`
-   `void pop()`
-   `int top()`
-   `int size()`

```c++
class MinHeap {
  private:
    int cap;   // 由于使用原始 arrary，需要确定最大容量
    int size;  // 当前堆大小
    int *harr; // 使用数组保存

    int parent(int idx) { return (idx - 1) / 2; }
    int left(int idx) { return 2 * idx + 1; }
    int right(int idx) { return 2 * idx + 2; }

    // 从底部向上父节点比较并交换
    void minHeapifyFromBottom(int idx) {
        if (idx == 0)
            return;
        int prtIdx = parent(idx);
        if (harr[prtIdx] > harr[idx]) {
            swap(harr[prtIdx], harr[idx]);
            minHeapifyFromBottom(prtIdx);
        }
    }
    // 从顶部与左右子节点比较并交换，与左右节点中小的子节点的交换，若都大，则直接 return
    void minHeapifyFromTop(int idx) {
        int leftIdx = left(idx);
        int rightIdx = right(idx);

        int min = harr[idx];
        int minIdx = idx;
        if (leftIdx < size && harr[leftIdx] < min) {
            min = harr[leftIdx];
            minIdx = leftIdx;
        }
        if (rightIdx < size && harr[rightIdx] < min) {
            min = harr[rightIdx];
            minIdx = rightIdx;
        }
        if (minIdx == idx) {
            return;
        }
        swap(harr[idx], harr[minIdx]);
        minHeapifyFromTop(minIdx);
    }

  public:
    // 构造函数，初始化最小堆
    MinHeap(int c) {
        cap = c;
        harr = new int[cap];
        size = 0;
    }
    // 先放到最尾部，然后从下向上 heapify，minHeapifyFromBottom
    void push(int data) {
        if (size == cap) {
            return;
        }
        size++;
        harr[size - 1] = data;
        minHeapifyFromBottom(size - 1);
    }
    // 先首位节点互换，忽略尾节点，然后从顶部开始向下 heapify，minHeapifyFromTop
    void pop() {
        if (size == 0)
            return;
        if (size == 1) {
            size = 0;
        }
        swap(harr[0], harr[size - 1]);
        size--;
        minHeapifyFromTop(0);
    }
    int top() {
        if (size == 0) {
            return -1;
        }
        return harr[0];
    }
    int heap_size() { return size; }
};
```
