# 912. 数组排序

## 快速排序

1. 取一个基准数 pivot
2. `partition()` 切分，左边的数都比 pivot 小，右边的数都比 pivot 大
3. 对切分好的两数组两部分，递归调用 `partition`

注意

-   时间复杂度 `O(nLogn)`
-   非稳定排序
-   当基准数一直取首位或末尾时，若原数组本来就是有序的，快排时间复杂度将降低为 `O(n^2)`，因此最好随机选择基准数

```c++
class Solution {
  public:
    vector<int> sortArray(vector<int> &nums) {
        srand((unsigned)time(NULL));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

  private:
    void quickSort(vector<int> &nums, int start, int end) {
        if (start < end) {
            int p = partition(nums, start, end);
            quickSort(nums, start, p - 1);
            quickSort(nums, p + 1, end);
        }
    }
    int partition(vector<int> &nums, int start, int end) {
        // 1.取末尾数位基准
        // int pivot = end;

        // 2.随机取一位作为基准数，当遇到已经排好序的数组时，就退化为了 n^2
        // 因此随机选择基准，rand()=0至RAND_MAX
        int pivot = start + rand() % (end - start);
        swap(nums[end], nums[pivot]);
        pivot = end;

        int index = start;
        for (int i = start; i < end; i++) {
            if (nums[i] < nums[pivot]) {
                swap(nums[i], nums[index]);
                index++;
            }
        }
        swap(nums[index], nums[end]);
        return index;
    }
};
```

## 归并排序

## 堆排序

参考 LeetCode 215 TopK 问题
