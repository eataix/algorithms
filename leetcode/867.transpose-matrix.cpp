#include <vector>
using namespace std;
/*
 * [898] Transpose Matrix
 *
 * https://leetcode.com/problems/transpose-matrix/description/
 *
 * algorithms
 * Easy (68.40%)
 * Total Accepted:    6.7K
 * Total Submissions: 9.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix A, return the transpose of A.
 *
 * The transpose of a matrix is the matrix flipped over it's main diagonal,
 * switching the row and column indices of the matrix.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 *
 *
 *
 */
class Solution {
public:
  vector<vector<int>> transpose(vector<vector<int>> &A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> B(n, vector<int>(m, 0));
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        B[r][c] = A[c][r];
      }
    }
    return B;
  }
};
