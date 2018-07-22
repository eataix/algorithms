#include <iostream>
#include <vector>
using namespace std;
/*
 * [562] Longest Line of Consecutive One in Matrix
 *
 * https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/description/
 *
 * algorithms
 * Medium (41.16%)
 * Total Accepted:    8.1K
 * Total Submissions: 19.8K
 * Testcase Example:  '[[0,1,1,0],[0,1,1,0],[0,0,0,1]]'
 *
 * Given a 01 matrix M, find the longest line of consecutive one in the matrix.
 * The line could be horizontal, vertical, diagonal or anti-diagonal.
 *
 * Example:
 *
 * Input:
 * [[0,1,1,0],
 * ⁠[0,1,1,0],
 * ⁠[0,0,0,1]]
 * Output: 3
 *
 *
 *
 *
 * Hint:
 * The number of elements in the given matrix will not exceed 10,000.
 *
 */
class Solution {
public:
  int longestLine(vector<vector<int>> &M) {
    if (M.empty() || M[0].empty()) {
      return 0;
    }
    auto numRows = M.size();
    auto numCols = M[0].size();
    vector<vector<vector<int>>> dp(
        numRows, vector<vector<int>>(numCols, vector<int>(4, 0)));

    int res = 0;
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (M[r][c] == 1) {
          dp[r][c][0] = r > 0 ? dp[r - 1][c][0] + 1 : 1;
          dp[r][c][1] = c > 0 ? dp[r][c - 1][1] + 1 : 1;
          dp[r][c][2] = (r > 0 && c > 0) ? dp[r - 1][c - 1][2] + 1 : 1;
          dp[r][c][3] =
              (r > 0 && c < numCols - 1) ? dp[r - 1][c + 1][3] + 1 : 1;

          for (int i = 0; i < 4; ++i) {
            res = max(res, dp[r][c][i]);
          }
        }
      }
    }

    return res;
  }
};
