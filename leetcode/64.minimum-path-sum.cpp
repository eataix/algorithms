#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
/*
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (40.95%)
 * Total Accepted:    149K
 * Total Submissions: 363.7K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 *
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 *
 *
 */
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    int numRows = grid.size();
    int numCols = grid[0].size();
    vector<vector<int>> dp = grid;
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (r == 0 && c == 0) {
          continue;
        }

        if (r == 0) {
          dp[r][c] += dp[r][c - 1];
        } else if (c == 0) {
          dp[r][c] += dp[r - 1][c];
        } else {
          dp[r][c] += min(dp[r - 1][c], dp[r][c - 1]);
        }
      }
    }
    return dp.back().back();
  }
};
