/*
 * @lc app=leetcode.cn id=146 lang=golang
 *
 * [146] LRU Cache
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (52.64%)
 * Likes:    1631
 * Dislikes: 0
 * Total Accepted:    231.4K
 * Total Submissions: 439.8K
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

package leetcode_146

import "container/list"

// @lc code=start

type entry struct {
	key   int
	value int
}
type LRUCache struct {
	evictList *list.List
	data      map[int]*list.Element
	cap       int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		evictList: list.New(),
		data:      make(map[int]*list.Element),
		cap:       capacity,
	}
}

func (this *LRUCache) Get(key int) int {
	e, ok := this.data[key]
	if !ok {
		return -1
	}
	v := e.Value.(*entry).value
	this.evictList.MoveToFront(e)
	return v
}

func (this *LRUCache) Put(key int, value int) {
	if e, ok := this.data[key]; ok {
		this.evictList.MoveToFront(e)
		e.Value.(*entry).value = value
		return
	}

	e := this.evictList.PushFront(&entry{key: key, value: value})
	this.data[key] = e

	if this.evictList.Len() > this.cap {
		old := this.evictList.Back()
		this.evictList.Remove(old)
		delete(this.data, old.Value.(*entry).key)
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end
