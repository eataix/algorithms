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
  int minPathSum(const vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> dp(cols);

    for (int r = rows - 1; r >= 0; --r) {
      for (int c = cols - 1; c >= 0; --c) {
        if (r == rows - 1 && c == cols - 1) {
          dp[c] = grid[r][c];
        } else if (r == rows - 1 && c != cols - 1) {
          dp[c] = grid[r][c] + dp[c + 1];
        } else if (r != rows - 1 && c == cols - 1) {
          dp[c] = grid[r][c] + dp[c];
        } else {
          dp[c] = grid[r][c] + min(dp[c], dp[c + 1]);
        }
      }
    }
    return dp[0];
  }
};
