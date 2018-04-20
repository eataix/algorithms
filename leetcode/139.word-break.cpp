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
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict{wordDict.cbegin(), wordDict.cend()};
    string s2 = '$' + s;
    vector<bool> dp{s2.size(), false};

    dp[0] = true;
    for (int i = 1; i < s2.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] = dp[j] && dict.find(s2.substr(j + 1, i - j)) != dict.cend();
        if (dp[i]) {
          break;
        }
      }
    }
    return dp[s2.size() - 1];
  }
};
