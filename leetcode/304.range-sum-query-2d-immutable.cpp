#include <vector>
using namespace std;
/*
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (27.97%)
 * Total Accepted:    47.3K
 * Total Submissions: 169K
 * Testcase Example:
 * '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 *
 *
 *
 * The above rectangle (with the red border) is defined by (row1, col1) = (2,
 * 1) and (row2, col2) = (4, 3), which contains sum = 8.
 *
 *
 * Example:
 *
 * Given matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 *
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 *
 *
 *
 * Note:
 *
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 *
 *
 */

class NumMatrix {
  size_t numRows;
  size_t numCols;
  vector<vector<int>> presum;

public:
  NumMatrix(vector<vector<int>> matrix)
      : numRows{matrix.size()}, numCols{numRows == 0 ? 0 : matrix[0].size()},
        presum(numRows + 1, vector<int>(numCols + 1, 0)) {
    for (int r = 1; r <= numRows; ++r) {
      for (int c = 1; c <= numCols; ++c) {
        presum[r][c] = presum[r][c - 1] + presum[r - 1][c] +
                       matrix[r - 1][c - 1] - presum[r - 1][c - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return presum[row2 + 1][col2 + 1] - presum[row1][col2 + 1] -
           presum[row2 + 1][col1] + presum[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
