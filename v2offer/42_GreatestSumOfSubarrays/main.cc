#include <iostream>
#include <vector>

using namespace std;

int findMaxSum(vector<int> data) {
    int length = data.size();
    if (length == 1) return data[0];
    int currentSum = data[0];
    int maxSum = currentSum;
    for (int i = 1; i < length; i++) {
        if (currentSum < 0) {
            currentSum = data[i];
        } else {
            currentSum += data[i];
        }
        if (currentSum > maxSum) maxSum = currentSum;
    }
    return maxSum;
}

int main() {
    vector<int> data = {-2,-1};
    int result = findMaxSum(data);
    cout << result << endl;
    return 0;
}