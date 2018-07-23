#include <iostream>

using namespace std;

int getNumberOne(int n) {
    int lowerNum = 0;
    int currNum = 0;
    int higherNum = 0;

    int cnt = 0;
    int m = 1;
    //从个位开始分别计算，个位，十位、、、上1的个数
    while (n / m != 0) {
        lowerNum = n - (n / m) * m;
        currNum = (n / m) % 10;
        higherNum = n / (m * 10);

        switch (currNum) {
            case 0:cnt += higherNum * m;
                break;
            case 1:cnt += higherNum * m + lowerNum + 1;
                break;
            default:cnt += (higherNum + 1) * m;
                break;
        }
        m *= 10;
    }
    return cnt;

//    下面是看不懂的leetcode大神答案 O(logN)
//    int cnt = 0;
//    for (int m = 1; m <= n; m *= 10) {
//        //2345 / 10
//        int a = n / m;  //除以10的次幂的 商 234
//        int b = n % m;  //除以10的次幂的 余数 5
//        cnt += (a + 8) / 10 * m + (a % 10 == 1 ? b + 1 : 0);
//    }
//    return cnt;
}

int main(int argc, char const **argv) {
    if (argc > 1) {
        int n = atoi(argv[1]);
        cout << getNumberOne(n);
    }
    return 0;
}