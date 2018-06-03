#include <queue>
#include <vector>
using namespace std;

class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer,
  // rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds,
  // if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds,
  // if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
  deque<NestedInteger> q;

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto a : nestedList) {
      q.push_back(a);
    }
  }

  int next() {
    NestedInteger ni = q.front();
    q.pop_front();
    return ni.getInteger();
  }

  bool hasNext() {
    while (!q.empty()) {
      NestedInteger ni = q.front();
      if (ni.isInteger()) {
        return true;
      }
      q.pop_front();
      auto list = ni.getList();
      for (auto it = crbegin(list); it != crend(list); ++it) {
        q.push_front(*it);
      }
    }
    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
