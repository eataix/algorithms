#include <vector>
using namespace std;
/*
 * [296] Best Meeting Point
 *
 * https://leetcode.com/problems/best-meeting-point/description/
 *
 * algorithms
 * Hard (52.69%)
 * Total Accepted:    18.3K
 * Total Submissions: 34.8K
 * Testcase Example:  '[[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]'
 *
 * A group of two or more people wants to meet and minimize the total travel
 * distance. You are given a 2D grid of values 0 or 1, where each 1 marks the
 * home of someone in the group. The distance is calculated using Manhattan
 * Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
 *
 * Example:
 *
 *
 * Input:
 *
 * 1 - 0 - 0 - 0 - 1
 * |   |   |   |   |
 * 0 - 0 - 0 - 0 - 0
 * |   |   |   |   |
 * 0 - 0 - 1 - 0 - 0
 *
 * Output: 6
 *
 * Explanation: Given three people living at (0,0), (0,4), and
 * (2,2):
 * The point (0,2) is an ideal meeting point, as the total travel
 * distance
 * of 2+2+2=6 is minimal. So return 6.
 *
 */
class Solution {
public:
  int minTotalDistance(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    int numRows = grid.size();
    int numCols = grid[0].size();

    vector<int> posR;
    vector<int> posC;

    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (grid[r][c] == 1) {
          posR.emplace_back(r);
          posC.emplace_back(c);
        }
      }
    }

    int med1 = posR[posR.size() / 2];

    nth_element(posC.begin(), posC.begin() + posC.size() / 2, posC.end());
    int med2 = posC[posC.size() / 2];

    int res = 0;
    for (auto pos1 : posR) {
      res += abs(pos1 - med1);
    }

    for (auto pos2 : posC) {
      res += abs(pos2 - med2);
    }
    return res;
  }
};
