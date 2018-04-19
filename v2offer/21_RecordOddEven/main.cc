#include <iostream>

//奇数在前偶数在后
int RecordOddEven(int *data, int length) {
    if (data == nullptr || length == 0) return -1;
    int *begin = data;              //指向首部的指针
    int *end = begin + length - 1;  //指向尾部元素的指针
    while (begin < end) {
        while (begin < end && *begin % 2 == 0) begin++;  //从头开始找到奇数
        while (begin < end && *end % 2 == 1) end--;  //从尾部开始找到偶数
        std::swap(*begin, *end);                     //两数进行交换
    }
    return begin - data;
}

int main() {
    int data[] = {1, 3, 4, 123, 43, 12, 55, 78, 2, 3, 1, 5, 4, 8, 8, 12};
    int length = sizeof(data) / sizeof(int);
    int split = RecordOddEven(data, length);
    return 0;
}