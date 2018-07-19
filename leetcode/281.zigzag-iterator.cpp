#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [281] Zigzag Iterator
 *
 * https://leetcode.com/problems/zigzag-iterator/description/
 *
 * algorithms
 * Medium (53.26%)
 * Total Accepted:    40.3K
 * Total Submissions: 75.6K
 * Testcase Example:  '[1,2]\n[3,4,5,6]'
 *
 * Given two 1d vectors, implement an iterator to return their elements
 * alternately.
 *
 * Example:
 *
 *
 * Input:
 * v1 = [1,2]
 * v2 = [3,4,5,6]
 *
 * Output: [1,3,2,4,5,6]
 *
 * Explanation: By calling next repeatedly until hasNext returns
 * false,
 * the order of elements returned by next should be: [1,3,2,4,5,6].
 *
 * Follow up: What if you are given k 1d vectors? How well can your code be
 * extended to such cases?
 *
 * Clarification for the follow up question:
 * The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases.
 * If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For
 * example:
 *
 *
 * Input:
 * [1,2,3]
 * [4,5,6,7]
 * [8,9]
 *
 * Output: [1,4,8,2,5,9,3,6,7].
 *
 *
 */
class ZigzagIterator {
  queue<pair<vector<int>::const_iterator, vector<int>::const_iterator>> q;
  vector<vector<int>> v;

public:
  ZigzagIterator(vector<int> &v1, vector<int> &v2) {
    if (!v1.empty()) {
      q.push({v1.cbegin(), v1.cend()});
    }

    if (!v2.empty()) {
      q.push({v2.cbegin(), v2.cend()});
    }
  }

  int next() {
    auto p = q.front();
    q.pop();
    if (p.first + 1 != p.second) {
      q.push({p.first + 1, p.second});
    }
    return *p.first;
  }

  bool hasNext() { return !q.empty(); }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
