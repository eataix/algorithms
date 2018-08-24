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
    vector<int> dp(rowIndex + 1, 0);
    dp[0] = 1;

    for (int r = 1; r <= rowIndex; ++r) {
      for (int c = r; c >= 1; --c) {
        dp[c] = dp[c] + dp[c - 1];
      }
    }
    return dp;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.getRow(3);
}
#endif
