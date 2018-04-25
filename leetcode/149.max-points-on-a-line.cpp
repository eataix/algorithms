#include <map>
#include <utility>
#include <vector>
using namespace std;
/*
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (15.19%)
 * Total Accepted:    92.5K
 * Total Submissions: 608.7K
 * Testcase Example:  '[]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
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
  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

public:
  int maxPoints(vector<Point> &points) {
    int res = 0;
    for (int i = 0; i < points.size(); ++i) {
      map<pair<int, int>, int> map;
      int duplicate = 1;
      for (int j = i + 1; j < points.size(); ++j) {
        if (points[i].x == points[j].x && points[i].y == points[j].y) {
          duplicate += 1;
        } else {
          int dx = points[j].x - points[i].x;
          int dy = points[j].y - points[i].y;
          int d = gcd(dx, dy);
          map[make_pair(dx / d, dy / d)] += 1;
        }
      }
      res = max(res, duplicate);

      for (auto kv : map) {
        res = max(res, kv.second + duplicate);
      }
    }
    return res;
  }
};
