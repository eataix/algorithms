#include <vector>
using namespace std;
/*
 * [751] Number Of Corner Rectangles
 *
 * https://leetcode.com/problems/number-of-corner-rectangles/description/
 *
 * algorithms
 * Medium (58.20%)
 * Total Accepted:    8.1K
 * Total Submissions: 13.9K
 * Testcase Example:  '[[0,1,0],[1,0,1],[1,0,1],[0,1,0]]'
 *
 * Given a grid where each entry is only 0 or 1, find the number of corner
 * rectangles.
 *
 * A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned
 * rectangle. Note that only the corners need to have the value 1. Also, all
 * four 1s used must be distinct.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: grid =
 * [[1, 0, 0, 1, 0],
 * ⁠[0, 0, 1, 0, 1],
 * ⁠[0, 0, 0, 1, 0],
 * ⁠[1, 0, 1, 0, 1]]
 * Output: 1
 * Explanation: There is only one corner rectangle, with corners grid[1][2],
 * grid[1][4], grid[3][2], grid[3][4].
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: grid =
 * [[1, 1, 1],
 * ⁠[1, 1, 1],
 * ⁠[1, 1, 1]]
 * Output: 9
 * Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and
 * one 3x3 rectangle.
 *
 *
 *
 *
 * Example 3:
 *
 *
 * Input: grid =
 * [[1, 1, 1, 1]]
 * Output: 0
 * Explanation: Rectangles must have four distinct corners.
 *
 *
 *
 *
 * Note:
 *
 *
 * The number of rows and columns of grid will each be in the range [1,
 * 200].
 * Each grid[i][j] will be either 0 or 1.
 * The number of 1s in the grid will be at most 6000.
 *
 *
 *
 *
 */
class Solution {
public:
  int countCornerRectangles(vector<vector<int>> &grid) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    int res = 0;

    vector<vector<int>> dp(numCols, vector<int>(numCols, 0));

    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (grid[r][c] == 1) {
          for (int c1 = c + 1; c1 < numCols; ++c1) {
            if (grid[r][c1] == 1) {
              res += dp[c][c1];
              dp[c][c1] += 1;
            }
          }
        }
      }
    }

    return res;
  }

  int countCornerRectangles2(vector<vector<int>> &grid) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    int res = 0;

    for (int r = 0; r < numRows; ++r) {
      for (int r1 = r + 1; r1 < numRows; ++r1) {
        int cnt = 0;

        for (int c = 0; c < numCols; c++) {
          if (grid[r][c] == 1 && grid[r1][c] == 1) {
            cnt += 1;
          }
        }

        res += (cnt * (cnt - 1)) >> 1;
      }
    }

    return res;
  }
};
