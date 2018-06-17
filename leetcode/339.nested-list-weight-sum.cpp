#include <vector>
using namespace std;
/*
 * [339] Nested List Weight Sum
 *
 * https://leetcode.com/problems/nested-list-weight-sum/description/
 *
 * algorithms
 * Easy (64.06%)
 * Total Accepted:    36.3K
 * Total Submissions: 56.7K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, return the sum of all integers in the list
 * weighted by their depth.
 *
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 *
 * Example 1:
 * Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at
 * depth 1)
 *
 * Example 2:
 * Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2,
 * and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)
 *
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer
 * to it. void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#ifdef DEBUG
class NestedInteger {
public:
  NestedInteger();
  NestedInteger(int value);
  bool isInteger() const;
  int getInteger() const;
  void setInteger(int value);
  void add(const NestedInteger &ni);
  const vector<NestedInteger> &getList() const;
};

#endif
class Solution {
public:
  int depthSum(vector<NestedInteger> &nestedList) {
    int res{0};
    for (auto const &i : nestedList) {
      dfs(i, res, 1);
    }
    return res;
  }

  void dfs(const NestedInteger &i, int &res, int level) {
    if (i.isInteger()) {
      res += i.getInteger() * level;
    } else {
      for (auto const &ni : i.getList()) {
        dfs(ni, res, level + 1);
      }
    }
  }
};
