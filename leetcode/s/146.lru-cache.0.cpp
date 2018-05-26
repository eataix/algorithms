#include <list>
#include <unordered_map>
#include <utility>
using namespace std;
/*
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (19.95%)
 * Total Accepted:    177.3K
 * Total Submissions: 879.3K
 * Testcase Example:
 * '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 *
 *
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 *
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 *
 * LRUCache cache = new LRUCache(2);
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 *
 *
 */
class LRUCache {
private:
  int cap;
  list<pair<int, int>> l;
  unordered_map<int, list<pair<int, int>>::iterator> m;

public:
  LRUCache(int capacity) : cap(capacity) {}

  int get(int key) {
    if (m.find(key) == cend(m)) {
      return -1;
    }
    l.splice(cbegin(l), l, m[key]);
    return l.front().second;
  }

  void put(int key, int value) {
    if (m.find(key) != end(m)) {
      l.erase(m[key]);
    }
    l.push_front({key, value});
    m[key] = begin(l);

    if (m.size() > cap) {
      auto p = l.back();
      int k = p.first;
      l.erase(m[k]);
      m.erase(k);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
