package leetcode

import "container/list"

type LRUCache struct {
	cap       int
	evictList *list.List
	items     map[int]*list.Element
}

type entry struct {
	key   int
	value int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		cap:       capacity,
		evictList: list.New(),
		items:     make(map[int]*list.Element),
	}
}

func (this *LRUCache) Get(key int) int {
	if e, ok := this.items[key]; ok {
		this.evictList.MoveToFront(e)
		if e.Value.(*entry) == nil {
			return -1
		}
		return e.Value.(*entry).value
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	elem := this.evictList.PushFront(&entry{
		key:   key,
		value: value,
	})
	e, ok := this.items[key]
	if ok {
		this.evictList.Remove(e)
		delete(this.items, key)
	}
	this.items[key] = elem

	if len(this.items) > this.cap {
		ent := this.evictList.Back()
		delete(this.items, ent.Value.(*entry).key)
		this.evictList.Remove(ent)
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
