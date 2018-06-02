#include <iostream>
#include <vector>
using namespace std;

//初始化时就循环遍历这个二维数据将其全部摊平储存在一个一维数组中
//保存一个变量i表示在摊平后的位置
// hasnext即判断i是否到末尾
class Vector2D2 {
   public:
    Vector2D2(vector<vector<int>>& vec2d) {
        for (auto v : vec2d) value.insert(value.end(), v.begin(), v.end());
    }

    int next() { return value[i++]; }

    bool hasNext() { return i < value.size(); }

   private:
    vector<int> value;
    int i = 0;
};

class Vector2D {
   public:
    Vector2D(vector<vector<int>>& vec2d) {
        end = vec2d.end();
        cur = vec2d.begin();  //表示目前的行
        n = 0;                //目前所处行的列
    }

    int next() {
        hasNext();  //这里执行hasnext是为了判断是否位于当前行的末尾，若在末尾需要转移到下一行并将列置为0
        return (*cur)[n++];
    }

    bool hasNext() {
        while (cur != end && cur->size() == n) {
            cur++;
            n = 0;
        }
        return cur != end;
    }

   private:
    vector<vector<int>>::iterator cur, end;
    int n;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
int main() {
    vector<vector<int>> vec2d = {{1, 2}, {3}, {4, 5, 6}};
    Vector2D i(vec2d);
    while (i.hasNext()) cout << i.next();
    return 0;
}