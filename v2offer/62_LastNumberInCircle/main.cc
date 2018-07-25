//
// Created by ruofeng on 2018/7/25.
//

#include <list>
#include <iostream>

using namespace std;

int josephus(int n, int k) {
    /* The position returned by josephus(n - 1, k) is adjusted because the
           recursive call josephus(n - 1, k) considers the original position
           k%n + 1 as position 1 */
    return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
}

int main() {
    cout << josephus(5, 3) << endl;
    return 0;
}