#include <string>
#include <vector>
using namespace std;
/*
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (21.05%)
 * Total Accepted:    125.6K
 * Total Submissions: 595K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 *
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "aa"
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 *
 *
 * Example 4:
 *
 *
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 *
 *
 * Example 5:
 *
 *
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 *
 *
 */
class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int pLen = 1; pLen <= n; ++pLen) {
      dp[0][pLen] = p[pLen - 1] == '*' && dp[0][pLen - 1];
    }

    for (int sLen = 1; sLen <= m; ++sLen) {
      for (int pLen = 1; pLen <= n; ++pLen) {
        if (p[pLen - 1] == '*') {
          dp[sLen][pLen] = dp[sLen - 1][pLen] || dp[sLen][pLen - 1];
        } else if (p[pLen - 1] == s[sLen - 1] || p[pLen - 1] == '?') {
          dp[sLen][pLen] = dp[sLen - 1][pLen - 1];
        }
      }
    }
    return dp.back().back();
  }
};
