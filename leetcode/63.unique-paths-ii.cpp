#include <vector>
using namespace std;
/*
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (32.47%)
 * Total Accepted:    147.4K
 * Total Submissions: 453.9K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 *
 *
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 *
 *
 */
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
      return 0;
    }

    int numRows = obstacleGrid.size();
    int numCols = obstacleGrid[0].size();
    vector<vector<int>> dp(numRows, vector<int>(numCols));

    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (obstacleGrid[r][c] == 1) {
          dp[r][c] = 0;
        } else if (r == 0 && c == 0) {
          dp[r][c] = 1;
        } else if (r == 0 && c > 0) {
          dp[r][c] = dp[r][c - 1];
        } else if (r > 0 && c == 0) {
          dp[r][c] = dp[r - 1][c];
        } else {
          dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
        }
      }
    }
    return dp.back().back();
  }
};
