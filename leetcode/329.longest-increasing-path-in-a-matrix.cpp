#include <vector>
using namespace std;
/*
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (37.61%)
 * Total Accepted:    56.9K
 * Total Submissions: 151.3K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 *
 * Example 1:
 *
 *
 * Input: nums =
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: nums =
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 *
 */
class Solution {
  vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

  int dfs(const vector<vector<int>> &matrix, int row, int col,
          vector<vector<int>> &dp) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    if (dp[row][col] != 0) {
      return dp[row][col];
    }

    for (auto dir : dirs) {
      int newRow = row + dir.first;
      int newCol = col + dir.second;

      if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols) {
        if (matrix[newRow][newCol] > matrix[row][col]) {
          dp[row][col] = max(dp[row][col], dfs(matrix, newRow, newCol, dp));
        }
      }
    }
    return ++dp[row][col];
  }

public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }

    int numRows = matrix.size();
    int numCols = matrix[0].size();

    vector<vector<int>> dp(numRows, vector<int>(numCols, 0));

    int res = 0;
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        res = max(res, dfs(matrix, r, c, dp));
      }
    }
    return res;
  }
};
