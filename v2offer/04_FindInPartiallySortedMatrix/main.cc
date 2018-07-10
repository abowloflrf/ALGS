#include <vector>
#include <iostream>

using namespace std;

bool find(vector<vector<int>> m, int target) {
    bool found = false;
    int maxRow = m.size();
    int maxCol = m[0].size();
    int row = 0;
    int col = maxCol - 1;
    while (row < maxRow && col >= 0) {
        if (m[row][col] == target) {
            found = true;
            break;
        } else if (m[row][col] > target)
            --col;
        else
            ++row;
    }
    return found;
}

int main() {
    vector<vector<int>> matrix = {
        {1,  2,  8,  9 }, 
        {2,  4,  9,  12}, 
        {4,  7,  10, 13}, 
        {6,  8,  11, 15}
    };
    bool result=find(matrix,5);
    cout<<result<<endl;
    return 0;
}
