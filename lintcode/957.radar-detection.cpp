#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#ifdef DEBUG
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};
#endif

class Solution {
public:
  /**
   * @param coordinates: The radars' coordinate
   * @param radius: Detection radius of radars
   * @return: The car was detected or not
   */
  string radarDetection(vector<Point> &coordinates, vector<int> &radius) {
    int n = coordinates.size();
    for (int i = 0; i < n; ++i) {
      int x = coordinates[i].x;
      int y = coordinates[i].y;
      int r = radius[i];

      if (abs(y) <= r) {
        return "YES";
      }
    }
    return "NO";
  }
};
