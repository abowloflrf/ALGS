#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct MyTreeNode {
    int val;    // 节点编号
    int locker; // 1-10000 表示被用户上锁 ，若 0 表示未上锁
    MyTreeNode *parent;

    MyTreeNode() : val(0), parent(nullptr), locker(0) {}
    MyTreeNode(int x) : val(x), parent(nullptr), locker(0) {}
};

class LockingTree {
  private:
    vector<MyTreeNode *> vtree; // son->prt 映射关系
    vector<vector<int>> sons;   // prt->son 映射关系

  public:
    LockingTree(vector<int> &parent) {
        for (int i = 0; i < parent.size(); i++) {
            vtree.push_back(new MyTreeNode(i));
        }
        sons = vector<vector<int>>(parent.size(), vector<int>{});
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] != -1) {
                vtree[i]->parent = vtree[parent[i]];
                sons[parent[i]].push_back(i);
            }
        }
    }

    bool lock(int num, int user) {
        if (vtree[num]->locker == 0) {
            vtree[num]->locker = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (vtree[num]->locker == user) {
            vtree[num]->locker = 0;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        MyTreeNode *target = vtree[num];
        // 该节点上锁、所有子孙节点都解锁

        // 1.自己不能锁
        if (vtree[num]->locker > 0)
            return false;

        // 2.至少有一个锁住的子孙节点
        vector<int> sonsToUnlock;
        queue<MyTreeNode *> sonQ;
        // 找第一遍，第一层子孙
        for (int i : sons[target->val]) {
            if (vtree[i]->locker > 0)
                sonsToUnlock.push_back(vtree[i]->val);
            sonQ.push(vtree[i]);
        }
        // 使用队列遍历所有子孙节点
        while (!sonQ.empty()) {
            for (int i = 0; i < sonQ.size(); i++) {
                for (int i : sons[sonQ.front()->val]) {
                    if (vtree[i]->locker > 0)
                        sonsToUnlock.push_back(vtree[i]->val);
                    sonQ.push(vtree[i]);
                }
                sonQ.pop();
            }
        }
        if (sonsToUnlock.empty())
            return false;

        // 3.没有任何上锁的祖先节点
        // 找所有的 parent
        MyTreeNode *prt = vtree[target->val]->parent;
        while (prt) {
            if (prt->locker > 0)
                return false;
            prt = vtree[prt->val]->parent;
        }

        // 上锁 与 解锁操作
        for (int t : sonsToUnlock) {
            vtree[t]->locker = 0;
        }
        lock(target->val, user);
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

int main(int argc, char const *argv[]) {
    //["LockingTree","upgrade","upgrade","unlock","lock","upgrade"]
    //[[[-1,0,3,1,0]],[4,5],[3,8],[0,7],[2,7],[4,6]]
    vector<int> parent = {-1, 0, 3, 1, 0};
    LockingTree *obj = new LockingTree(parent);

    bool b;
    // b = obj->lock(4, 2);
    // b = obj->unlock(2, 3);
    // b = obj->unlock(2, 2);
    // b = obj->lock(4, 5);
    // b = obj->upgrade(0, 1);
    // b = obj->lock(0, 1);
    b = obj->upgrade(4, 5);
    b = obj->upgrade(3, 8);
    return 0;
}
