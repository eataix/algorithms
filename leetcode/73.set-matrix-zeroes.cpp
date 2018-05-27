#include <vector>
using namespace std;
/*
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (36.75%)
 * Total Accepted:    142.4K
 * Total Submissions: 387.5K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output:
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output:
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 *
 *
 * Follow up:
 *
 *
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 *
 *
 */
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return;
    }
    bool col0 = false;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int r = 0; r < rows; ++r) {
      if (matrix[r][0] == 0) {
        col0 = true;
      }
      for (int c = 1; c < cols; ++c) {
        if (matrix[r][c] == 0) {
          matrix[r][0] = matrix[0][c] = 0;
        }
      }
    }

    for (int r = rows - 1; r >= 0; --r) {
      for (int c = cols - 1; c >= 1; --c) {
        if (matrix[r][0] == 0 || matrix[0][c] == 0) {
          matrix[r][c] = 0;
        }
      }
      if (col0) {
        matrix[r][0] = 0;
      }
    }
  }
};
