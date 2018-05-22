#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
using namespace std;
/*
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (19.96%)
 * Total Accepted:    175.1K
 * Total Submissions: 872.7K
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
 * LRUCache cache = new LRUCache( 2 );
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
public:
  LRUCache(int capacity) { cap = capacity; }

  int get(int key) {
    auto it = m.find(key);
    if (it == m.cend()) {
      return -1;
    }

    l.splice(l.begin(), l, it->second);
    return it->second->second;
  }

  void put(int key, int value) {
    auto it = m.find(key);
    if (it != m.cend()) {
      l.erase(it->second);
    }
    l.push_front(make_pair(key, value));
    m[key] = l.begin();
    if (m.size() > cap) {
      int k = l.rbegin()->first;
      l.pop_back();
      m.erase(k);
    }
  }

private:
  int cap;
  list<pair<int, int>> l;
  unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

#ifdef DEBUG
int main() {
  LRUCache cache{2 /* capacity */};
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl; // returns 1
  cache.put(3, 3);              // evicts key 2
  cout << cache.get(2) << endl; // returns -1 (not found)
  cache.put(4, 4);              // evicts key 1
  cout << cache.get(1) << endl; // returns -1 (not found)
  cout << cache.get(3) << endl; // returns 3
  cout << cache.get(4) << endl; // returns 4
}
#endif
