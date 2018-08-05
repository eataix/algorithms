#include <vector>
using namespace std;
/*
 * [880] Rectangle Area II
 *
 * https://leetcode.com/problems/rectangle-area-ii/description/
 *
 * algorithms
 * Hard (42.23%)
 * Total Accepted:    1.5K
 * Total Submissions: 3.6K
 * Testcase Example:  '[[0,0,2,2],[1,0,2,3],[1,0,3,1]]'
 *
 * We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = [x1,
 * y1, x2, y2] , where (x1, y1) are the coordinates of the bottom-left corner,
 * and (x2, y2) are the coordinates of the top-right corner of the ith
 * rectangle.
 *
 * Find the total area covered by all rectangles in the plane.  Since the
 * answer may be too large, return it modulo 10^9 + 7.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
 * Output: 6
 * Explanation: As illustrated in the picture.
 *
 *
 * Example 2:
 *
 *
 * Input: [[0,0,1000000000,1000000000]]
 * Output: 49
 * Explanation: The answer is 10^18 modulo (10^9 + 7), which is (10^9)^2 =
 * (-7)^2 = 49.
 *
 *
 * Note:
 *
 *
 * 1 <= rectangles.length <= 200
 * rectanges[i].length = 4
 * 0 <= rectangles[i][j] <= 10^9
 * The total area covered by all rectangles will never exceed 2^63 - 1 and thus
 * will fit in a 64-bit signed integer.
 *
 */
class Solution {
public:
  int rectangleArea(vector<vector<int>> &rectangles) {
    int OPEN = 0;
    int CLOSE = 1;
    int numRects = rectangles.size();
    vector<vector<int>> events(numRects * 2);

    int t = 0;
    for (auto const &rect : rectangles) {
      events[t++] = vector<int>{rect[1], OPEN, rect[0], rect[2]};
      events[t++] = vector<int>{rect[3], CLOSE, rect[0], rect[2]};
    }
    auto cmp = [](const vector<int> &v1, const vector<int> &v2) {
      return v1[0] < v2[0];
    };

    sort(events.begin(), events.end(), cmp);

    vector<vector<int>> active;
    int cur_y = events[0][0];
    long ans = 0;

    for (auto const &event : events) {
      int y = event[0], typ = event[1], x1 = event[2], x2 = event[3];

      long query = 0;
      int cur = -1;
      for (auto const &xs : active) {
        cur = max(cur, xs[0]);
        query += max(xs[1] - cur, 0);
        cur = max(cur, xs[1]);
      }

      ans += query * (y - cur_y);

      if (typ == OPEN) {
        active.push_back({x1, x2});
        sort(active.begin(), active.end(), cmp);
      } else {
        for (int i = 0; i < active.size(); ++i)
          if (active[i][0] == x1 && active[i][1] == x2) {
            active.erase(active.begin() + i);
            break;
          }
      }

      cur_y = y;
    }

    ans %= 1000000007;
    return (int)ans;
  }
};
