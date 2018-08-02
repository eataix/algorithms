#include <vector>
using namespace std;
/*
 * [587] Erect the Fence
 *
 * https://leetcode.com/problems/erect-the-fence/description/
 *
 * algorithms
 * Hard (33.66%)
 * Total Accepted:    5.2K
 * Total Submissions: 15.4K
 * Testcase Example:  '[[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]'
 *
 * There are some trees, where each tree is represented by (x,y) coordinate in
 * a two-dimensional garden. Your job is to fence the entire garden using the
 * minimum length of rope as it is expensive. The garden is well fenced only if
 * all the trees are enclosed. Your task is to help find the coordinates of
 * trees which are exactly located on the fence perimeter.
 *
 * Example 1:
 *
 * Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
 * Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
 * Explanation:
 *
 *
 *
 *
 * Example 2:
 *
 * Input: [[1,2],[2,2],[4,2]]
 * Output: [[1,2],[2,2],[4,2]]
 * Explanation:
 *
 * Even you only have trees in a line, you need to use rope to enclose
 * them.
 *
 *
 *
 * ⁠Note:
 *
 * All trees should be enclosed together. You cannot cut the rope to enclose
 * trees that will separate them in more than one group.
 * All input integers will range from 0 to 100.
 * The garden has at least one tree.
 * All coordinates are distinct.
 * Input points have NO order. No order required for output.
 *
 *
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#ifdef DEBUG
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};
#endif

class Solution {
  typedef int coord_t;
  typedef long long coord2_t;

  coord2_t cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (coord2_t)(B.y - O.y) -
           (A.y - O.y) * (coord2_t)(B.x - O.x);
  }

public:
  vector<Point> outerTrees(vector<Point> &points) {
    auto n = points.size();
    auto k = 0;
    vector<Point> H(2 * n);
    auto cmp = [](const Point &p1, const Point &p2) {
      return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
    };

    sort(points.begin(), points.end(), cmp);

    for (int i = 0; i < n; ++i) {
      while (k >= 2 && cross(H[k - 2], H[k - 1], points[i]) < 0) {
        k -= 1;
      }
      H[k++] = points[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; i--) {
      while (k >= t && cross(H[k - 2], H[k - 1], points[i]) < 0)
        k--;
      H[k++] = points[i];
    }

    // Remove duplicates
    H.resize(k);
    sort(H.begin(), H.end(), cmp);
    H.erase(unique(H.begin(), H.end(),
                   [](const Point &p1, const Point &p2) {
                     return p1.x == p2.x && p1.y == p2.y;
                   }),
            H.end());
    return H;
  }
};
