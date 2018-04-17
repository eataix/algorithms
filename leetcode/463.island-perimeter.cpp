#include <vector>
using namespace std;
/*
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (57.89%)
 * Total Accepted:    78.2K
 * Total Submissions: 135.1K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water. Grid cells are connected
 * horizontally/vertically (not diagonally). The grid is completely surrounded
 * by water, and there is exactly one island (i.e., one or more connected land
 * cells). The island doesn't have "lakes" (water inside that isn't connected
 * to the water around the island). One cell is a square with side length 1.
 * The grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 *
 * Example:
 *
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 *
 * Answer: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 *
 *
 *
 */
class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    if (grid.size() == 0) {
      return 0;
    }
    int n = grid.size();
    int m = grid[0].size();
    int total = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          total += 4;
          if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            total -= 2;
          }
          if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            total -= 2;
          }
        }
      }
    }
    return total;
  }
};
