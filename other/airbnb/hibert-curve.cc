#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    long long hilbert_curve(int x, int y, int iter) {
        if (iter == 0) return 1;

        long long halfLen = (1 << (iter - 1));      //边长的一半
        long long halfNum = (1 << (2 * iter - 2));  //单个象限大小

        //曲线的路径是 3->2->1->4
        //因此每在3象限之后要多走几个halfNum步

        if (x >= halfLen && y >= halfLen)       //第一象限
            return 2 * halfNum + hilbert_curve(x - halfLen, y - halfLen, iter - 1);
        else if (x < halfLen && y >= halfLen)   //第二象限
            return halfNum + hilbert_curve(x, y - halfLen, iter - 1);
        else if (x < halfLen && y < halfLen)    //第三象限
            return hilbert_curve(y, x, iter - 1);
        else                                    //第四象限
            return 3 * halfNum + hilbert_curve(halfLen - 1 - y, 2 * halfLen - 1 - x, iter - 1);
    }
};

int main() {
    Solution solution;
    cout << solution.hilbert_curve(1, 1, 2) << endl;
    cout << solution.hilbert_curve(0, 1, 1) << endl;
    cout << solution.hilbert_curve(2, 2, 2) << endl;
    cout << solution.hilbert_curve(1, 3, 2) << endl;
    cout << solution.hilbert_curve(3, 1, 2) << endl;
    cout << solution.hilbert_curve(12, 55, 6) << endl;
    return 0;
}
