#include <algorithm>
using namespace std;
/*
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (42.90%)
 * Total Accepted:    189.5K
 * Total Submissions: 441.8K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 *
 *
 * Example 2:
 *
 *
 * Input: m = 7, n = 3
 * Output: 28
 *
 */

class Solution {
private:
  long long bionomialCoefficient(long long n, long long k) {
    if (k < 0 || k > n) {
      return 0;
    }
    if (k == 0 || k == n) {
      return 1;
    }

    k = min(k, n - k);

    long long c = 1;
    for (int i = 0; i < k; ++i) {
      c = c * (n - i) / (i + 1);
    }
    return c;
  }

public:
  int uniquePaths(int m, int n) {
    m -= 1;
    n -= 1;
    return bionomialCoefficient(m + n, n);
  }
};

/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        if (m == 1|| n ==1) {
            return 1;
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));

        for (int i = 2; i<= m; ++i) {
            for (int j = 2; j <= n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m][n];
    }
};
*/
