#include <vector>
using namespace std;
/*
 * [311] Sparse Matrix Multiplication
 *
 * https://leetcode.com/problems/sparse-matrix-multiplication/description/
 *
 * algorithms
 * Medium (52.83%)
 * Total Accepted:    48.8K
 * Total Submissions: 92.4K
 * Testcase Example:  '[[1,0,0],[-1,0,3]]\n[[7,0,0],[0,0,0],[0,0,1]]'
 *
 * Given two sparse matrices A and B, return the result of AB.
 *
 * You may assume that A's column number is equal to B's row number.
 *
 * Example:
 *
 *
 * Input:
 *
 * A = [
 * ⁠ [ 1, 0, 0],
 * ⁠ [-1, 0, 3]
 * ]
 *
 * B = [
 * ⁠ [ 7, 0, 0 ],
 * ⁠ [ 0, 0, 0 ],
 * ⁠ [ 0, 0, 1 ]
 * ]
 *
 * Output:
 *
 * ⁠    |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
 * AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
 * ⁠                 | 0 0 1 |
 *
 *
 */
class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
    int m = A.size();
    int n = A[0].size();
    int nB = B[0].size();

    vector<vector<int>> C(m, vector<int>(nB, 0));

    for (int i = 0; i < m; ++i) {
      for (int k = 0; k < n; ++k) {
        if (A[i][k] != 0) {
          for (int j = 0; j < nB; ++j) {
            if (B[k][j] != 0) {
              C[i][j] += A[i][k] * B[k][j];
            }
          }
        }
      }
    }
    return C;
  }
};
