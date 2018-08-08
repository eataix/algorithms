#include <limits>
#include <string>
#include <vector>
using namespace std;
/*
 * [727] Minimum Window Subsequence
 *
 * https://leetcode.com/problems/minimum-window-subsequence/description/
 *
 * algorithms
 * Hard (32.02%)
 * Total Accepted:    6.7K
 * Total Submissions: 21K
 * Testcase Example:  '"abcdebdde"\n"bde"'
 *
 * Given strings S and T, find the minimum (contiguous) substring W of S, so
 * that T is a subsequence of W.
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "". If there are multiple such minimum-length windows, return
 * the one with the left-most starting index.
 *
 * Example 1:
 *
 *
 * Input:
 * S = "abcdebdde", T = "bde"
 * Output: "bcde"
 * Explanation:
 * "bcde" is the answer because it occurs before "bdde" which has the same
 * length.
 * "deb" is not a smaller window because the elements of T in the window must
 * occur in order.
 *
 *
 *
 *
 * Note:
 *
 *
 * All the strings in the input will only contain lowercase letters.
 * The length of S will be in the range [1, 20000].
 * The length of T will be in the range [1, 100].
 *
 *
 *
 *
 */
class Solution {
public:
  string minWindow(string S, string T) {
    int m = S.size(), n = T.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= m; ++i) {
      dp[i][0] = i;
    }
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= min(i, n); ++j) {
        dp[i][j] = (S[i - 1] == T[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j];
      }
    }

    int start = -1, minLen = numeric_limits<int>::max();
    for (int i = 1; i <= m; ++i) {
      if (dp[i][n] != -1) {
        int len = i - dp[i][n];
        if (minLen > len) {
          minLen = len;
          start = dp[i][n];
        }
      }
    }
    return (start != -1) ? S.substr(start, minLen) : "";
  }
};
