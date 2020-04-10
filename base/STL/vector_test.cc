#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec) {
    for (auto data : vec) {
        cout << data << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2(vec1.begin(), vec1.end());
    vector<int> vec3(vec1);
    vector<int> vec4(10, 42);
    printVector(vec1);
    printVector(vec2);
    printVector(vec3);
    printVector(vec4);
    return 0;
}
