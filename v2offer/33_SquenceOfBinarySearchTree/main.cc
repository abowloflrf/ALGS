#include <vector>
#include <iostream>

using namespace std;

bool isBST(vector<int> squence) {
    int length = squence.size();
    if (length == 1) return true;
    //后序遍历的末尾必定是root
    int rootValue = squence.back();
    //找到左右子树的分割地
    int splitIndex = 0;
    for (splitIndex = 0; splitIndex < length - 1; splitIndex++) {
        if (squence[splitIndex] > rootValue) break;
    }
    for (int i = splitIndex + 1; i < length - 1; i++) {
        if (squence[i] < rootValue) return false;
    }
    bool left = true;
    if (splitIndex > 0)
        left = isBST(vector<int>(squence.begin(), squence.begin() + splitIndex));
    bool right = true;
    if (splitIndex < length - 1)
        right = isBST(vector<int>(squence.begin() + splitIndex, squence.end() - 1));

    return left && right;
}

int main() {
    vector<int> testSquence = {5, 7, 6, 9, 11, 10, 8};
    bool result = isBST(testSquence);
    cout << result << endl;
    return 0;
}