#include <iostream>
#include <string>

using namespace std;

// replace " " with "%20"
void replaceSpaces(string &s) {
    int len = s.size();
    int spaceNum = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') spaceNum++;
    }
    if (spaceNum == 0) return;

    int newSize = len + 2 * spaceNum;

    s.resize(newSize);
    int pLast = newSize - 1;
    int pFront = len - 1;
    for (int i = 0; i < len; i++) {
        if (s[pFront] != ' ') {
            s[pLast--] = s[pFront];
        } else {
            s[pLast--] = '0';
            s[pLast--] = '2';
            s[pLast--] = '%';
        }
        pFront--;
    }
}
int main() {
    string str = " We are happ y ";
    replaceSpaces(str);
    cout<<str<<endl;
    return 0;
}