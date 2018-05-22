#include <algorithm>
using namespace std;
/*
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (33.83%)
 * Total Accepted:    71.6K
 * Total Submissions: 211.4K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 *
 *
 *
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem, creating the above
 * image and all test cases.
 *
 */
class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int sum = (C - A) * (D - B) + (H - F) * (G - E);
    if (E >= C || F >= D || B > H || A >= G) {
      return sum;
    } else {
      return sum - (min(G, C) - max(A, E)) * (min(D, H) - max(B, F));
    }
  }
};
