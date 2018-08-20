#include <iostream>
#include <vector>
using namespace std;
/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (40.13%)
 * Total Accepted:    169.5K
 * Total Submissions: 422.4K
 * Testcase Example:  '5'
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 *
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 *
 *
 */
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res(numRows);

    for (int i = 0; i < numRows; ++i) {
      res[i].resize(i + 1);
      res[i][0] = res[i][i] = 1;

      for (int j = 1; j < i; ++j) {
        res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
      }
    }

#ifdef DEBUG
    for (auto v : res) {
      for (auto j : v) {
        cout << j << " ";
      }
      cout << endl;
    }
#endif

    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.generate(10);
}
#endif
