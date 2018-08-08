#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
/*
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (37.79%)
 * Total Accepted:    109.5K
 * Total Submissions: 289.8K
 * Testcase Example:  '1'
 *
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 *
 *
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
 * return 2 because 13 = 4 + 9.
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 *
 *
 * https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
 */
class Solution {
private:
  bool is_square(int n) {
    int s = static_cast<int>(sqrt(n));
    return s * s == n;
  }

public:
  int numSquares(int n) {
    vector<int> dp(n + 1, numeric_limits<int>::max());
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }

  int numSquares2(int n) {
    if (is_square(n)) {
      return 1;
    }

    while (n % 4 == 0) {
      n /= 4;
    }

    if (n % 8 == 7) {
      return 4;
    }

    int sqrt_n = static_cast<int>(sqrt(n));
    for (int i = 1; i <= sqrt_n; ++i) {
      if (is_square(n - i * i)) {
        return 2;
      }
    }
    return 3;
  }
};
