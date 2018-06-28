class Solution {
public:
  /**
   * @param matrix: A lsit of lists of integers
   * @return: nothing
   */
  void setZeroes(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    bool firstCol = false;

    for (int r = 0; r < rows; ++r) {
      if (matrix[r][0] == 0) {
        firstCol = true;
        break;
      }
    }

    for (int r = 0; r < rows; ++r) {
      for (int c = 1; c < cols; ++c) {
        if (matrix[r][c] == 0) {
          matrix[r][0] = 0;
          matrix[0][c] = 0;
        }
      }
    }

    for (int r = rows - 1; r >= 0; --r) {
      for (int c = cols - 1; c >= 1; --c) {
        if (matrix[r][0] == 0 || matrix[0][c] == 0) {
          matrix[r][c] = 0;
        }
      }
    }

    if (firstCol) {
      for (int r = 0; r < rows; ++r) {
        matrix[r][0] = 0;
      }
    }
  }
};
