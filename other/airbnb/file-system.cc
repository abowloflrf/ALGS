#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
   private:
    unordered_map<string, int> pathMap;

   public:
    Solution() { pathMap[""] = 0; }
    bool create(string path, int value) {
        if (pathMap.count(path)) return false;

        int slashIndex = path.size() - 1;
        for (int i = path.size() - 1; i >= 0; i--) {
            if (path[i] != '/')
                slashIndex--;
            else
                break;
        }
        string lastPath = path.substr(0, slashIndex);
        if (pathMap.count(lastPath) == 0) return false;
        pathMap[path] = value;
        return true;
    }

    int get(string path) {
        if (pathMap.count(path))
            return pathMap[path];
        else
            return -1;
    }
};

int main() {
    Solution s = Solution();
    s.create("/a", 12);
    s.create("/a/b", 13);
    s.create("/a/c/d", 11);
    s.create("/a/c", 10);
    int a = s.get("/a");
    int b = s.get("/a/c/d");
    int c = s.get("/aaa");
    return 0;
}