#include <string>
#include <vector>

using namespace std;
/*
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (54.68%)
 * Total Accepted:    39.3K
 * Total Submissions: 71.9K
 * Testcase Example:  '"abc"'
 *
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 *
 *
 *
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 *
 *
 * Example 1:
 *
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 *
 *
 * Example 2:
 *
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 *
 *
 * Note:
 *
 * The input string length won't exceed 1000.
 *
 *
 */
class Solution {
public:
  int countSubstrings(const string &s) {
    auto n{s.size()};
    int res{0};

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
        if (dp[i][j]) {
          res += 1;
        }
      }
    }
    return res;
  }

  int countSubstrings1(const string &s) {
    if (s.size() <= 1) {
      return s.size();
    }

    int res{0};
    for (int i = 0; i < s.size(); ++i) {
      helper(s, i, i, res);
      helper(s, i, i + 1, res);
    }
    return res;
  }

  void helper(const string &s, int left, int right, int &res) {
    while (left > 0 && right < s.size() && s[left] == s[right]) {
      res += 1;
      left += 1;
      right -= 1;
    }
  }
};
