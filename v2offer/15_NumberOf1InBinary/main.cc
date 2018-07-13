#include <bitset>
#include <iostream>
#include <string>
using namespace std;

//设置一个标志与目标进行与运算，每次运算将标志右移一位
//一直到int尽头，即要循环32次，开销过大
int getOne(int num) {
    int flag = 1;
    int count = 0;
    while (flag) {
        if (num & flag) count++;
        flag <<= 1;
    }
    return count;
}

//有多少个1就循环多少次，开销最小
int betterGetOne(int num) {
    int count = 0;
    while (num) {
        count++;
        //一个数与其减一的结果进行与运算，会将结果最右边的1变为0
        num = (num - 1) & num;
    }
    return count;
}
int main(int argc, char const *argv[]) {
    if (argc > 1) {
        int targetNumber = stoi(argv[1]);

        cout << bitset<sizeof(int) * 8>(targetNumber) << endl;
        cout << getOne(targetNumber) << endl;
        cout << betterGetOne(targetNumber) << endl;

        return 0;
    }
}
