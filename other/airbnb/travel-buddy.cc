/**
 * Buddy List
 * 先将自己的list保存在set中，然后遍历所有其他人的list
 * 若 相同的城市/list.size() > 0.5 则保存这个人以及其相似度
 * 最后将保存下来的所有大于0.5的列表排序，从大到小排序
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Buddy {
    string name;
    unordered_set<int> cities;
    float similarity;

   public:
    Buddy(string n, unordered_set<int> c, float s) {
        name = n;
        cities = c;
        similarity = s;
    }
    bool operator<(const Buddy &b) { return similarity > b.similarity; }
};

vector<Buddy> getBuddy(unordered_set<int> myList,
                       unordered_map<string, unordered_set<int>> otherLists) {
    int mySize = myList.size();
    vector<Buddy> res;
    for (auto l : otherLists) {
        int paired = 0;
        for (auto c : l.second) {
            if (myList.count(c)) paired++;
        }

        if (paired > mySize / 2)
            res.push_back(Buddy(l.first, l.second, (float)paired / mySize));
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    unordered_map<string, unordered_set<int>> list;
    list["a"] = {1, 2, 3, 4, 5};
    list["b"] = {2, 3, 5, 6, 9, 10};
    list["c"] = {5, 6, 7};
    list["d"] = {1, 2, 8, 9, 11};
    list["e"] = {11, 23};
    list["f"] = {2, 3, 4, 5, 10, 11, 12};
    unordered_set<int> myList = {2, 3, 4, 5, 7, 12, 13};
    vector<Buddy> res = getBuddy(myList, list);
    return 0;
}