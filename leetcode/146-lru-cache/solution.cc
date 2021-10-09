/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (52.66%)
 * Likes:    1618
 * Dislikes: 0
 * Total Accepted:    228.3K
 * Total Submissions: 433.6K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 *
 * Implement the LRUCache class:
 *
 *
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 *
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 *
 *
 */
#include <list>
#include <unordered_map>
using namespace std;

// @lc code=start
class LRUCache {
  private:
    int cap;
    // *双向链表 list 保存 key->value 数据链表，按访问属性排列
    list<pair<int, int>> dataList;
    // map 保存 key -> datalist 节点的指针映射
    unordered_map<int, list<pair<int, int>>::iterator> positionMap;

  public:
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        // 从 map 中找到数据的指针
        auto t = positionMap.find(key);
        if (t == positionMap.end()) {
            return -1;
        }
        // *将访问到的链表元素移动到链表首部
        dataList.splice(dataList.begin(), dataList, t->second);
        return t->second->second;
    }

    void put(int key, int value) {
        dataList.push_front({key, value});
        // 在 map 中找
        auto it = positionMap.find(key);
        // 若找到，则替换 map 中的指针，并将原来链表中的元素移除
        if (it != positionMap.end()) {
            dataList.erase(it->second);
        }
        // 不管找没找到 map 中 key 指向的元素指针替换为新加入的节点指针
        positionMap[key] = dataList.begin();

        // 判断是否满，若满则一出最旧的元素
        if (positionMap.size() > cap) {
            positionMap.erase(dataList.back().first);
            dataList.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(int argc, char const *argv[]) {

    LRUCache l(2);
    l.put(1, 1);
    l.put(2, 2);
    l.get(1);
    l.put(3, 3);
    l.get(2);
    l.put(4, 4);
    l.get(1);
    l.get(3);
    l.get(4);

    return 0;
}
