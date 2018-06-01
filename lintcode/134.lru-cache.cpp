#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

class LRUCache {
private:
  int capacity;
  unordered_map<int, list<pair<int, int>>::iterator> m;
  list<pair<int, int>> l;

public:
  /*
   * @param capacity: An integer
   */
  LRUCache(int capacity) : capacity(capacity) {
    // do intialization if necessary
  }

  /*
   * @param key: An integer
   * @return: An integer
   */
  int get(int key) {
    if (m.find(key) == cend(m)) {
      return -1;
    }
    auto it = m[key];
    l.splice(l.begin(), l, it);
    return it->second;
  }

  /*
   * @param key: An integer
   * @param value: An integer
   * @return: nothing
   */
  void set(int key, int value) {
    if (m.find(key) != cend(m)) {
      l.erase(m[key]);
    }
    l.push_front({key, value});
    m[key] = l.begin();

    if (m.size() > capacity) {
      auto kv = l.back();
      l.erase(m[kv.first]);
      m.erase(kv.first);
    }
  }
};
