#include <string>
#include <vector>
using namespace std;
/*
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (44.82%)
 * Total Accepted:    20.3K
 * Total Submissions: 45.2K
 * Testcase Example:  '"sea"\n"eat"'
 *
 *
 * Given two words word1 and word2, find the minimum number of steps required
 * to make word1 and word2 the same, where in each step you can delete one
 * character in either string.
 *
 *
 * Example 1:
 *
 * Input: "sea", "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 *
 *
 *
 * Note:
 *
 * The length of given words won't exceed 500.
 * Characters in given words can only be lower-case letters.
 *
 *
 */
class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return len1 + len2 - 2 * dp.back().back();
  }
};
