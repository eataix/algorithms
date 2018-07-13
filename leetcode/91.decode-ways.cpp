#include <string>
#include <vector>
using namespace std;
/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (20.61%)
 * Total Accepted:    182.3K
 * Total Submissions: 884.8K
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 *
 * Example 1:
 *
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 *
 */
class Solution {
public:
  int numDecodings(string s) {
    if (s.empty()) {
      return 0;
    }
    vector<int> dp(s.size() + 1, 0);

    dp[0] = 1;

    for (int i = 1; i < dp.size(); ++i) {
      if (s[i - 1] != '0') {
        dp[i] += dp[i - 1];
      }

      if (i >= 2 && s.substr(i - 2, 2) <= "26" && s.substr(i - 2, 2) >= "10") {
        dp[i] += dp[i - 2];
      }
    }

    return dp.back();
  }
};
