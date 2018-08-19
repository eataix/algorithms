#include <vector>
using namespace std;
/*
 * [308] Range Sum Query 2D - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-mutable/description/
 *
 * algorithms
 * Hard (26.95%)
 * Total Accepted:    24.4K
 * Total Submissions: 90.7K
 * Testcase Example:
 * '["NumMatrix","sumRegion","update","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[3,2,2],[2,1,4,3]]'
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
 * update(3, 2, 2)
 * sumRegion(2, 1, 4, 3) -> 10
 *
 *
 *
 * Note:
 *
 * The matrix is only modifiable by the update function.
 * You may assume the number of calls to update and sumRegion function is
 * distributed evenly.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 *
 *
 */

class NumMatrix {
  vector<vector<int>> mat;
  vector<vector<int>> bit;
  int numRows;
  int numCols;

  static inline int lowbit(int i) { return i & (-i); }

  int getSum(int row, int col) {
    row += 1;
    col += 1;
    int res = 0;
    for (int r = row; r > 0; r -= lowbit(r)) {
      for (int c = col; c > 0; c -= lowbit(c)) {
        res += bit[r][c];
      }
    }
    return res;
  }

public:
  NumMatrix(const vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return;
    }
    numRows = matrix.size();
    numCols = matrix[0].size();
    mat.resize(numRows + 1, vector<int>(numCols + 1, 0));
    bit.resize(numRows + 1, vector<int>(numCols + 1, 0));

    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        update(r, c, matrix[r][c]);
      }
    }
  }

  void update(int row, int col, int val) {
    row += 1;
    col += 1;
    int diff = val - mat[row][col];
    for (int r = row; r <= numRows; r += lowbit(r)) {
      for (int c = col; c <= numCols; c += lowbit(c)) {
        bit[r][c] += diff;
      }
    }

    mat[row][col] = val;
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return getSum(row2, col2) - getSum(row1 - 1, col2) -
           getSum(row2, col1 - 1) + getSum(row1 - 1, col1 - 1);
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
