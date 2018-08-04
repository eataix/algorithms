#include <string>
#include <vector>
using namespace std;
/*
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (32.70%)
 * Total Accepted:    87.4K
 * Total Submissions: 267.4K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 *
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 *
 * Example 1:
 *
 *
 * Input: S = "rabbbit", T = "rabbit"
 * Output: 3
 * Explanation:
 *
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * (The caret symbol ^ means the chosen letters)
 *
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 *
 *
 * Example 2:
 *
 *
 * Input: S = "babgbag", T = "bag"
 * Output: 5
 * Explanation:
 *
 * As shown below, there are 5 ways you can generate "bag" from S.
 * (The caret symbol ^ means the chosen letters)
 *
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 *
 *
 */
class Solution {
public:
  int numDistinct(string s, string t) {
    if (t.size() > s.size()) {
      return 0;
    }

    vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));
    // dp[i][j]: the numer of subsequences of s[0, 1, 2, ..., j] that contains
    // t[0, 1, 2, ..., i]

    for (int j = 0; j <= s.size(); ++j) {
      dp[0][j] = 1;
    }

    for (int i = 1; i <= t.size(); ++i) {
      for (int j = 1; j <= s.size(); ++j) {
        if (t[i - 1] == s[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    return dp.back().back();
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.numDistinct("rabbbit", "rabbit");
}
#endif
