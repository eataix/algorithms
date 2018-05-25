#include <string>
#include <vector>
using namespace std;
/*
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (21.07%)
 * Total Accepted:    125.9K
 * Total Submissions: 596.1K
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
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= p.size(); ++i) {
      if (p[i - 1] == '*') {
        dp[0][i] = dp[0][i - 1];
      }
    }

    for (int i = 1; i <= s.size(); ++i) {
      char sc = s[i - 1];
      for (int j = 1; j <= p.size(); ++j) {
        char pc = p[j - 1];
        if (pc == '*') {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        } else if (pc == '?' || pc == sc) {
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }
    return dp.back().back();
  }
};
