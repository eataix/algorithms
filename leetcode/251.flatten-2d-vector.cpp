#include <vector>
using namespace std;
/*
 * [251] Flatten 2D Vector
 *
 * https://leetcode.com/problems/flatten-2d-vector/description/
 *
 * algorithms
 * Medium (41.78%)
 * Total Accepted:    39.4K
 * Total Submissions: 94.3K
 * Testcase Example:  '[[1,2],[3],[4,5,6]]'
 *
 * Implement an iterator to flatten a 2d vector.
 *
 * Example:
 *
 *
 * Input: 2d vector =
 * [
 * ⁠ [1,2],
 * ⁠ [3],
 * ⁠ [4,5,6]
 * ]
 * Output: [1,2,3,4,5,6]
 * Explanation: By calling next repeatedly until hasNext returns
 * false,
 * the order of elements returned by next should be: [1,2,3,4,5,6].
 *
 * Follow up:
 * As an added challenge, try to code it using only iterators in C++ or
 * iterators in Java.
 *
 */
class Vector2D {
  vector<vector<int>>::const_iterator i, end;
  int j = 0;

public:
  Vector2D(const vector<vector<int>> &vec2d) {
    i = vec2d.cbegin();
    end = vec2d.cend();
  }

  int next() { return (*i)[j++]; }

  bool hasNext() {
    while (i != end && j == (*i).size()) {
      i += 1;
      j = 0;
    }
    return i != end;
  }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
