#include <stack>
#include <vector>
using namespace std;
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
#ifdef DEBUG
class NestedInteger {
public:
  bool isInteger() const;
  int getInteger() const;
  const vector<NestedInteger> &getList() const;
};
#endif

class NestedIterator {
  stack<NestedInteger> s;

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto it = nestedList.crbegin(); it != nestedList.crend(); ++it) {
      s.push(*it);
    }
  }

  // @return {int} the next element in the iteration
  int next() {
    auto ni = s.top();
    s.pop();
    return ni.getInteger();
  }

  // @return {boolean} true if the iteration has more element or false
  bool hasNext() {
    while (!s.empty()) {
      auto ni = s.top();
      if (ni.isInteger()) {
        return true;
      }

      s.pop();
      auto list = ni.getList();
      for (auto it = list.crbegin(); it != list.crend(); ++it) {
        s.push(*it);
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
