#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (31.55%)
 * Total Accepted:    208.5K
 * Total Submissions: 660.7K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words. You may assume the dictionary does
 * not contain duplicate words.
 *
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 *
 *
 * Return true because "leetcode" can be segmented as "leet code".
 *
 *
 *
 * UPDATE (2017/1/4):
 * The wordDict parameter had been changed to a list of strings (instead of a
 * set of strings). Please reload the code definition to get the latest
 * changes.
 *
 */
class Solution {
public:
  bool wordBreak2(string s, vector<string> &wordDict) {
    unordered_set<string> dict{wordDict.begin(), wordDict.end()};
    vector<bool> dp(s.size() + 1, false);

    dp[0] = true;

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] = dp[j] && dict.count(s.substr(j, i - j));
        if (dp[i]) {
          break;
        }
      }
    }
    return dp.back();
  }

  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp(s.size() + 1, false);

    dp[0] = true;

    for (int len = 1; len <= s.size(); ++len) {
      for (auto const &word : wordDict) {
        int start = len - word.size();
        if (start >= 0) {
          string newStr = s.substr(start, word.size());
          dp[len] = dp[start] && newStr == word;
          if (dp[len]) {
            break;
          }
        }
      }
    }

    return dp.back();
  }
};
