/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (46.07%)
 * Likes:    431
 * Dislikes: 0
 * Total Accepted:    36.2K
 * Total Submissions: 78.7K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据
 put 。
 *
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 *
 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
 *
 * 进阶:
 *
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 *
 * 示例:
 *
 * LRUCache cache = new LRUCache( 2 );
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得密钥 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得密钥 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 *
 *
 */

#include <list>
#include <unordered_map>
using namespace std;

// @lc code=start
class LRUCache {
  public:
    LRUCache(int capacity) { this->cap = capacity; }

    int get(int key) {
        auto it = positionMap.find(key);
        if (it == positionMap.end()) {
            return -1;
        }
        // 将找到的*ListNode插入到dataList头部
        dataList.splice(dataList.begin(), dataList, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = positionMap.find(key);
        // 将新的kv对插入到list头部
        dataList.push_front({key, value});
        // 若原cache中有这个key，则先将原来的数据删除
        // 若不存在，则直接在map插入新数据
        if (it != positionMap.end()) {
            dataList.erase(it->second);
            positionMap.erase(it);
        }
        positionMap[key] = dataList.begin();

        // 判断当前容量是否满
        if (positionMap.size() > cap) {
            positionMap.erase(dataList.back().first);
            dataList.pop_back();
        }
    }

  private:
    int cap;
    list<pair<int, int>> dataList;
    unordered_map<int, list<pair<int, int>>::iterator> positionMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

// 定义一个Value结构体，保存真正的value和指向list中的迭代器
struct Value {
    int v;
    list<int>::iterator iter;
    Value(int v, list<int>::iterator it) : iter(it), v(v) {}
};

class LRUCache2 {
  public:
    LRUCache2(int capacity) { this->cap = capacity; }

    int get(int key) {
        auto it = dataMap.find(key);
        if (it == dataMap.end()) {
            return -1;
        }
        // 将找到的*ListNode插入到dataList头部
        visitList.splice(visitList.begin(), visitList, it->second.iter);
        return it->second.v;
    }

    void put(int key, int value) {
        auto it = dataMap.find(key);
        // 将新的kv对插入到list头部
        visitList.push_front(key);
        // 若原cache中有这个key，则先将原来的数据删除
        // 若不存在，则直接在map插入新数据
        if (it != dataMap.end()) {
            visitList.erase(it->second.iter);
            dataMap.erase(it->first);
        }
        Value v(value, visitList.begin());
        dataMap.insert(pair<int, Value>(key, v));

        // 判断当前容量是否满
        if (dataMap.size() > cap) {
            dataMap.erase(visitList.back());
            visitList.pop_back();
        }
    }

  private:
    int cap;                           // 当前容量
    list<int> visitList;               // 双向链表，保存访问记录
    unordered_map<int, Value> dataMap; // map保存kv对， 其中v还有指向访问记录链表的迭代器
};