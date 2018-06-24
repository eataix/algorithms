#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

class LRUCache {
  list<pair<int, int>> l;
  unordered_map<int, list<pair<int, int>>::iterator> m;
  int cap;

public:
  /*
   * @param capacity: An integer
   */
  LRUCache(int capacity) : cap(capacity) {
    // do intialization if necessary
  }

  /*
   * @param key: An integer
   * @return: An integer
   */
  int get(int key) {
    if (m.count(key)) {
      l.splice(l.begin(), l, m[key]);

      return l.cbegin()->second;
    } else {
      return -1;
    }
  }

  /*
   * @param key: An integer
   * @param value: An integer
   * @return: nothing
   */
  void set(int key, int value) {
    if (m.count(key)) {
      l.erase(m[key]);
    }
    l.push_front({key, value});
    m[key] = l.begin();

    if (l.size() > cap) {
      auto p = l.back();
      m.erase(p.first);
      l.pop_back();
    }
  }
};
