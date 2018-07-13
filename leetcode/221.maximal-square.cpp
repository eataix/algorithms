#include <vector>
using namespace std;
/*
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (30.40%)
 * Total Accepted:    87.3K
 * Total Submissions: 287.2K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 *
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Return 4.
 *
 *
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }

    int numRows = matrix.size();
    int numCols = matrix[0].size();

    vector<vector<int>> dp(numRows + 1, vector<int>(numCols + 1, 0));

    int maxSqrtLen = 0;

    for (int r = 1; r <= numRows; ++r) {
      for (int c = 1; c <= numCols; ++c) {
        if (matrix[r - 1][c - 1] == '1') {
          dp[r][c] = min(min(dp[r][c - 1], dp[r - 1][c]), dp[r - 1][c - 1]) + 1;
          maxSqrtLen = max(maxSqrtLen, dp[r][c]);
        }
      }
    }

    return maxSqrtLen * maxSqrtLen;
  }
};
