#include <iostream>
#include <vector>
using namespace std;
/*
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (38.25%)
 * Total Accepted:    144.4K
 * Total Submissions: 377.6K
 * Testcase Example:  '3'
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    int numRows = rowIndex + 1;
    vector<int> res(numRows, 0);
    cout << res.size() << endl;

    res[0] = 1;

    for (int i = 1; i <= numRows; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (j == 0 || j == i - 1) {
          res[j] = 1;
        } else {
          res[j] = res[j] + res[j - 1];
        }
      }
    }

#ifdef DEBUG
    for (int k = 0; k < res.size(); ++k) {
      cout << res[k] << " ";
    }
    cout << endl;
#endif

    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.getRow(3);
}
#endif
