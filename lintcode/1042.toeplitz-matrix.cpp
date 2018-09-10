class Solution {
public:
  /**
   * @param matrix: the given matrix
   * @return: True if and only if the matrix is Toeplitz
   */
  bool isToeplitzMatrix(vector<vector<int>> &matrix) {
    for (int r = 1; r < matrix.size(); ++r) {
      for (int c = 1; c < matrix[0].size(); ++c) {
        if (matrix[r - 1][c - 1] != matrix[r][c]) {
          return false;
        }
      }
    }
    return true;
  }
};
