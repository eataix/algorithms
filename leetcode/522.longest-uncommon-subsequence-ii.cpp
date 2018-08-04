#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
 * [522] Longest Uncommon Subsequence II
 *
 * https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/
 *
 * algorithms
 * Medium (32.21%)
 * Total Accepted:    12.8K
 * Total Submissions: 39.8K
 * Testcase Example:  '["aba","cdc","eae"]'
 *
 *
 * Given a list of strings, you need to find the longest uncommon subsequence
 * among them. The longest uncommon subsequence is defined as the longest
 * subsequence of one of these strings and this subsequence should not be any
 * subsequence of the other strings.
 *
 *
 *
 * A subsequence is a sequence that can be derived from one sequence by
 * deleting some characters without changing the order of the remaining
 * elements. Trivially, any string is a subsequence of itself and an empty
 * string is a subsequence of any string.
 *
 *
 *
 * The input will be a list of strings, and the output needs to be the length
 * of the longest uncommon subsequence. If the longest uncommon subsequence
 * doesn't exist, return -1.
 *
 *
 * Example 1:
 *
 * Input: "aba", "cdc", "eae"
 * Output: 3
 *
 *
 *
 * Note:
 *
 * All the given strings' lengths will not exceed 10.
 * The length of the given list will be in the range of [2, 50].
 *
 *
 */
class Solution {
  bool isSubsequence(const string &s, const string &t) {
    auto si = s.cbegin();
    auto ti = t.cbegin();

    for (; si != s.cend() && ti != t.cend(); ++ti) {
      if (*si == *ti) {
        si += 1;
      }
    }

    return si == s.cend();
  }

public:
  int findLUSlength(vector<string> &strs) {
    sort(strs.begin(), strs.end(), [](const string &str1, const string &str2) {
      return str1.size() > str2.size();
    });

    int res = -1;
    for (int i = 0; i < strs.size(); ++i) {
      int j = 0;
      for (; j < strs.size(); ++j) {
        if (i == j) {
          continue;
        }
        if (isSubsequence(strs[i], strs[j])) {
          break;
        }
      }
      if (j == strs.size()) {
        return strs[i].size();
      }
    }

    return -1;
  }
};
