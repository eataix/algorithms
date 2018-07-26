#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [391] Perfect Rectangle
 *
 * https://leetcode.com/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (27.65%)
 * Total Accepted:    15.2K
 * Total Submissions: 54.8K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 *
 * Given N axis-aligned rectangles where N > 0, determine if they all together
 * form an exact cover of a rectangular region.
 *
 *
 *
 * Each rectangle is represented as a bottom-left point and a top-right point.
 * For example, a unit square is represented as [1,1,2,2]. (coordinate of
 * bottom-left point is (1, 1) and top-right point is (2, 2)).
 *
 *
 *
 * Example 1:
 *
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [3,2,4,4],
 * ⁠ [1,3,2,4],
 * ⁠ [2,3,3,4]
 * ]
 *
 * Return true. All 5 rectangles together form an exact cover of a rectangular
 * region.
 *
 *
 *
 *
 *
 *
 * Example 2:
 *
 * rectangles = [
 * ⁠ [1,1,2,3],
 * ⁠ [1,3,2,4],
 * ⁠ [3,1,4,2],
 * ⁠ [3,2,4,4]
 * ]
 *
 * Return false. Because there is a gap between the two rectangular
 * regions.
 *
 *
 *
 *
 *
 *
 * Example 3:
 *
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [1,3,2,4],
 * ⁠ [3,2,4,4]
 * ]
 *
 * Return false. Because there is a gap in the top center.
 *
 *
 *
 *
 *
 *
 * Example 4:
 *
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [1,3,2,4],
 * ⁠ [2,2,4,4]
 * ]
 *
 * Return false. Because two of the rectangles overlap with each other.
 *
 *
 *
 *
 */
class Solution {
  void eraseIfExist(unordered_set<string> &s, const string &str) {
    if (s.count(str)) {
      s.erase(str);
    } else {
      s.insert(str);
    }
  }

  string pointToString(int x, int y) {
    return to_string(x) + "," + to_string(y);
  }

public:
  bool isRectangleCover(vector<vector<int>> &rectangles) {
    unordered_set<string> s;
    int minX = numeric_limits<int>::max();
    int minY = numeric_limits<int>::max();
    int maxX = numeric_limits<int>::min();
    int maxY = numeric_limits<int>::min();
    int area = 0;

    for (auto const &rect : rectangles) {
      auto blX = rect[0];
      auto blY = rect[1];
      auto trX = rect[2];
      auto trY = rect[3];
      minX = min(minX, blX);
      minY = min(minY, blY);
      maxX = max(maxX, trX);
      maxY = max(maxY, trY);

      area += (trY - blY) * (trX - blX);

      auto s1 = pointToString(blX, blY);
      auto s2 = pointToString(blX, trY);
      auto s3 = pointToString(trX, trY);
      auto s4 = pointToString(trX, blY);

      eraseIfExist(s, s1);
      eraseIfExist(s, s2);
      eraseIfExist(s, s3);
      eraseIfExist(s, s4);
    }

    auto t1 = pointToString(minX, minY);
    auto t2 = pointToString(minX, maxY);
    auto t3 = pointToString(maxX, maxY);
    auto t4 = pointToString(maxX, minY);

    if (!s.count(t1) || !s.count(t2) || !s.count(t3) || !s.count(t4) ||
        s.size() != 4) {
      return false;
    }

    return area == (maxX - minX) * (maxY - minY);
  }
};
