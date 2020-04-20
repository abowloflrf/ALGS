/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (30.70%)
 * Likes:    1174
 * Dislikes: 111
 * Total Accepted:    65.9K
 * Total Submissions: 200.4K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Frequently Used (LFU) cache.
 * It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reaches its capacity, it should invalidate the least
 * frequently used item before inserting a new item. For the purpose of this
 * problem, when there is a tie (i.e., two or more keys that have the same
 * frequency), the least recently used key would be evicted.
 *
 * Note that the number of times an item is used is the number of calls to the
 * get and put functions for that item since it was inserted. This number is
 * set to zero when the item is removed.
 *
 *
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 *
 *
 * Example:
 *
 *
 * LFUCache cache = new LFUCache;
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.get(3);       // returns 3.
 * cache.put(4, 4);    // evicts key 1.
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 *
 *
 *
 *
 */

#include <list>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;
// @lc code=start

// 保存 key/value 和访问的次数
struct Node {
    int key, val, freq;
    Node(int _key, int _val, int _freq) : key(_key), val(_val), freq(_freq) {}
};

class LFUCache {
  public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        minF = 0;
        key_table.clear();
        freq_table.clear();
    }

    int get(int key) {
        if (capacity == 0)
            return -1;
        auto it = key_table.find(key);
        if (it == key_table.end())
            return -1;
        // 找到目标节点
        auto nodeIt = it->second;
        Node *nodeP = *nodeIt;

        int val = nodeP->val, freq = nodeP->freq;
        // 更新freq
        // 从freq_table中移除该节点
        freq_table[freq].erase(nodeIt);
        // 先判断还有没有相同freq的key，若没有了则minF+1
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (freq == minF)
                this->minF++;
        }
        // 将节点的freq+1后插入到freq_table的freq+1的位置
        // 若有freq+1的位置，插入到头部，没有则为freq_map新建一个list
        nodeP->freq++;
        if (freq_table.find(freq + 1) != freq_table.end())
            freq_table[freq + 1].push_front(nodeP);
        else
            freq_table[freq + 1] = list<Node *>{nodeP};
        // 更新key_table指向的节点
        key_table[key] = freq_table[freq + 1].begin();

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 原cache中不存在此key

            // 先判断容量是否超过容量，超过则先做删除minF位置节点的操作
            if (key_table.size() == capacity) {
                auto backNode = freq_table[minF].back();
                freq_table[minF].pop_back();
                key_table.erase(backNode->key);
            }
            // 再插入新的节点
            if (freq_table.find(1) != freq_table.end())
                freq_table[1].push_front(new Node(key, value, 1));
            else
                freq_table[1] = list<Node *>{new Node(key, value, 1)};
            key_table[key] = freq_table[1].begin();
            minF = 1;
        } else {
            // 原cache中已存在此key

            // 记录旧节点的freq，后面的步骤与get操作类似，只是val都是新的value
            auto nodeIt = key_table[key];
            Node *nodeP = *nodeIt;
            int freq = nodeP->freq;
            // 删除freq_table中指向list中的目标节点
            freq_table[freq].erase(nodeIt);
            if (freq_table[freq].size() == 0) {
                // freq_table中此freq的list数量为空，删除此map中此freq的key
                freq_table.erase(freq);
                if (freq == minF)
                    this->minF++;
            }
            // 若有freq+1的位置，插入到头部，没有则为freq_map新建一个list
            nodeP->val = value;
            nodeP->freq++;
            if (freq_table.find(freq + 1) != freq_table.end())
                freq_table[freq + 1].push_front(nodeP);
            else
                freq_table[freq + 1] = list<Node *>{nodeP};
            // 更新key_table指向的节点
            key_table[key] = freq_table[freq + 1].begin();
        }
    }

  private:
    unordered_map<int, list<Node *>::iterator> key_table;
    unordered_map<int, list<Node *>> freq_table;
    int capacity;
    int minF; // 关键，记录目前最小的使用频率
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main() {
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    int v1 = cache.get(1);
    cache.put(3, 3);
    int v2 = cache.get(2);
    int v3 = cache.get(3);
    cache.put(4, 4);
    int v4 = cache.get(1);
    int v5 = cache.get(3);
    int v6 = cache.get(4);

    return 0;
}