#include <string>
#include <vector>
using namespace std;
/*
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (36.57%)
 * Total Accepted:    126.5K
 * Total Submissions: 346K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * Example:
 *
 *
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 *
 *
 */
class Solution {
  bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
      if (s[start] != s[end]) {
        return false;
      }
      start += 1;
      end -= 1;
    }
    return true;
  }
  void dfs(const string &s, int idx, vector<vector<string>> &res,
           vector<string> &out) {
    if (idx == s.size()) {
      res.push_back(out);
      return;
    }

    for (int i = idx; i < s.size(); ++i) {
      if (isPalindrome(s, idx, i)) {
        out.push_back(s.substr(idx, i - idx + 1));
        dfs(s, i + 1, res, out);
        out.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    if (s.empty()) {
      return {};
    }

    vector<vector<string>> res;
    vector<string> out;
    dfs(s, 0, res, out);
    return res;
  }
};
