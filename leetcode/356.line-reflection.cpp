#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
/*
 * [356] Line Reflection
 *
 * https://leetcode.com/problems/line-reflection/description/
 *
 * algorithms
 * Medium (30.43%)
 * Total Accepted:    15.4K
 * Total Submissions: 50.5K
 * Testcase Example:  '[[1,1],[-1,1]]'
 *
 * Given n points on a 2D plane, find if there is such a line parallel to
 * y-axis that reflect the given points.
 *
 *
 * ⁠   Example 1:
 *
 *
 * Given points = [[1,1],[-1,1]], return true.
 *
 *
 *
 * ⁠   Example 2:
 *
 *
 * Given points = [[1,1],[-1,-1]], return false.
 *
 *
 * Follow up:
 * Could you do better than O(n2)?
 *
 *
 * Credits:Special thanks to @memoryless for adding this problem and creating
 * all test cases.
 */

class Solution {
public:
  bool isReflected(vector<pair<int, int>> &points) {
    int maxX = numeric_limits<int>::min();
    int minX = numeric_limits<int>::max();

    unordered_map<string, unordered_set<int>> m;

    for (int i = 0; i < points.size(); ++i) {
      auto point = points[i];
      auto x = point.first;
      auto y = point.second;

      maxX = max(maxX, x);
      minX = min(minX, x);
      m[to_string(x) + "," + to_string(y)].insert(i);
    }

    int sum = maxX + minX;
    for (int i = 0; i < points.size(); ++i) {
      auto point = points[i];
      auto x = point.first;
      auto y = point.second;
      auto str = to_string(sum - x) + "," + to_string(y);
      if (!m.count(str)) {
        return false;
      }
    }
    return true;
  }
};
