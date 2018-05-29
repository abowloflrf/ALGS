#include <vector>
using namespace std;
int singleNumber(vector<int> &A) {
    int single = 0;
    for (auto v : A) {
        single ^= v;  //异或
    }
    return single;
}

int main(int argc, char const *argv[]) {
    vector<int> vec = {1, 2, 2, 1, 3, 4, 3};
    int ret = singleNumber(vec);
    return 0;
}