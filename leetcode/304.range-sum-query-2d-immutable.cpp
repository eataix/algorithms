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
  vector<vector<int>> rowSums;
  int numRows;
  int numCols;

public:
  NumMatrix(vector<vector<int>> matrix) {
    numRows = matrix.size();
    if (numRows == 0) {
      numCols = 0;
      return;
    }
    numCols = matrix[0].size();
    rowSums.resize(numRows);
    for (int r = 0; r < numRows; ++r) {
      rowSums[r].resize(numCols + 1);
      rowSums[r][0] = 0;
      for (int c = 0; c < numCols; ++c) {
        rowSums[r][c + 1] = rowSums[r][c] + matrix[r][c];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int res = 0;
    for (int r = row1; r <= row2; ++r) {
      res += rowSums[r][col2 + 1] - rowSums[r][col1];
    }
    return res;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */