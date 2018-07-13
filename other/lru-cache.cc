// LRU - Least Recently Used
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

using namespace std;

class LRUCache {
   public:
    LRUCache(int capacity) : capacity(capacity){};
    string get(string key) {
        auto it = positionMap.find(key);
        //若map中未找到key，则返回错误信息
        if (it == positionMap.end()) {
            return "NotFound";
        }
        //在list中找到get的pair并将它移动并插入到list头部
        dataList.splice(dataList.begin(), dataList, it->second);
        return it->second->second;
    }
    void put(string key, string value) {
        auto it = positionMap.find(key);
        //将 pair 插入到列表头部
        dataList.push_front({key, value});
        if (it != positionMap.end()) {
            dataList.erase(it->second);
            positionMap.erase(it);
        }
        positionMap[key] = dataList.begin();
        //容量已满，则将list中最后一位（最近最久未使用的一项）从list与map中移除
        if (positionMap.size() > capacity) {
            positionMap.erase(dataList.back().first);
            dataList.pop_back();
        }
    }

   private:
    // cache的最大容量
    size_t capacity;
    // list 中储存的的是需要保存的键值对
    // 读取时会将目标项移动到头部
    // 写入是直接插入到头部
    list<pair<string, string>> dataList;
    // map 保存查找表，保存的是key与list迭代器的对应
    // 每次查询时根据key从map拿到迭代器可以直接在list中得到相应value
    unordered_map<string, list<pair<string, string>>::iterator> positionMap;
};

int main() {
    LRUCache cache(10);
    cache.put("foo", "bar");
    cache.put("name", "ruofeng");
    cache.put("phone", "iPhone 7");
    cache.put("PC", "XPS 13");
    cache.put("CPU", "i5 7200U");
    cout << cache.get("name") << endl;
    cout << cache.get("PC") << endl;
    return 0;
}