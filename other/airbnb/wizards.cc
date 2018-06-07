#include <climits>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Wizard {
   public:
    int idx, dis;
    Wizard(int i, int d) {
        idx = i;
        dis = d;
    }
};

int cost(vector<vector<int>> costList) {
    int n = costList.size();
    vector<Wizard> wizards;
    //初始化所有距离为intmax
    for (int i = 0; i < n; i++) {
        if (i == 0)
            wizards.push_back(Wizard(i, 0));
        else
            wizards.push_back(Wizard(i, INT_MAX));
    }
    // bfs
    queue<Wizard> q;
    q.push(wizards[0]);
    while (!q.empty()) {
        Wizard w = q.front();
        q.pop();
        for (int i : costList[w.idx]) {
            int newDis = w.dis + (w.idx - i) * (w.idx - i);
            //距离有更新则入队，计算下一层
            if (wizards[i].dis > newDis) {
                wizards[i].dis = newDis;
                q.push(wizards[i]);
            }
        }
    }
    return wizards[n - 1].dis;
}

int main() {
    vector<vector<int>> list;
    list.push_back({1, 3});
    list.push_back({2});
    list.push_back({});
    list.push_back({2});
    int c = cost(list);
    return 0;
}