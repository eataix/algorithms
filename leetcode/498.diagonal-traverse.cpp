#include <vector>
using namespace std;
/*
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (45.42%)
 * Total Accepted:    20.9K
 * Total Submissions: 45.9K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 *
 *
 * Example:
 *
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output:  [1,2,4,7,5,3,6,8,9]
 * Explanation:
 *
 *
 *
 *
 * Note:
 *
 * The total number of elements of the given matrix will not exceed 10,000.
 *
 *
 */
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int r = 0;
    int c = 0;
    int k = 0;

    vector<int> res(n * m);
    vector<pair<int, int>> dirs{{-1, 1}, {1, -1}};

    for (int i = 0; i < n * m; ++i) {
      res[i] = matrix[r][c];
      r += dirs[k].first;
      c += dirs[k].second;

      if (r >= m) {
        r = m - 1;
        c += 2;
        k = 1 - k;
      }

      if (c >= n) {
        c = n - 1;
        r += 2;
        k = 1 - k;
      }

      if (r < 0) {
        r = 0;
        k = 1 - k;
      }

      if (c < 0) {
        c = 0;
        k = 1 - k;
      }
    }
    return res;
  }
};
