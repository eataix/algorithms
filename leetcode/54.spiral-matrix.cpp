#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (27.35%)
 * Total Accepted:    142.7K
 * Total Submissions: 521.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 */

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ret;
    if (matrix.empty() || matrix[0].empty()) {
      return ret;
    }
    int r1{0};
    int r2{static_cast<int>(matrix.size() - 1)};

    int c1{0};
    int c2{static_cast<int>(matrix[0].size() - 1)};

    while (r1 <= r2 && c1 <= c2) {
      for (int c = c1; c <= c2; c++) {
        ret.push_back(matrix[r1][c]);
      }

      for (int r = r1 + 1; r <= r2; r++) {
        ret.push_back(matrix[r][c2]);
      }
      if (r1 < r2 && c1 < c2) {
        for (int c = c2 - 1; c > c1; c--) {
          ret.push_back(matrix[r2][c]);
        }
        for (int r = r2; r > r1; r--) {
          ret.push_back(matrix[r][c1]);
        }
      }

      r1 += 1;
      r2 -= 1;
      c1 += 1;
      c2 -= 1;
    }
    return ret;
  }
};
