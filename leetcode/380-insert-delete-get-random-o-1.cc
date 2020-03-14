/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1/description/
 *
 * algorithms
 * Medium (44.16%)
 * Likes:    1796
 * Dislikes: 127
 * Total Accepted:    173.7K
 * Total Submissions: 382.2K
 * Testcase Example:  '["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]\n' +
  '[[],[1],[2],[2],[],[1],[2],[]]'
 *
 * Design a data structure that supports all following operations in average
 * O(1) time.
 *
 *
 *
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each
 * element must have the same probability of being returned.
 *
 *
 *
 * Example:
 *
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 *
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 *
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 *
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 *
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 *
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 *
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 *
 * // Since 2 is the only number in the set, getRandom always return 2.
 * randomSet.getRandom();
 *
 *
 */
#include <ctime>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class RandomizedSet {
  public:
    /** Initialize your data structure here. */
    RandomizedSet() { srand(time(0)); }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (dataMap.find(val) != dataMap.end())
            return false;
        dataMap[val] = dataList.size();
        dataList.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (dataMap.find(val) == dataMap.end())
            return false;
        // 在list中将目标元素与末尾元素交换
        int idx = dataMap[val];
        int endVal = dataList.back();
        swap(dataList[idx], dataList[dataList.size() - 1]);
        // 将原末尾的元素在map中value的index换成刚刚替换的位置
        dataMap[endVal] = idx;
        // 删除目标元素
        dataMap.erase(val);
        dataList.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() { return dataList[rand() % dataList.size()]; }

  private:
    vector<int> dataList;
    unordered_map<int, int> dataMap;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
int main(int argc, char const *argv[])
{
    RandomizedSet s;
    s.insert(1);
    s.insert(10);
    s.insert(20);
    s.insert(30);
    int  r;
    r = s.getRandom();
    r = s.getRandom();
    return 0;
}
