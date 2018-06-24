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
    for (int i = 0; i < coordinates.size(); ++i) {
      int upper = coordinates[i].y + radius[i];
      int lower = coordinates[i].y - radius[i];

      if ((upper > 0 && lower < 0) || (upper > 1 && lower < 1)) {
        return "YES";
      }
    }
    return "NO";
  }
};
