#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * [800] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (53.12%)
 * Total Accepted:    16.7K
 * Total Submissions: 31.4K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.  Return a list of all possible
 * strings we could create.
 *
 *
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 *
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 *
 * Input: S = "12345"
 * Output: ["12345"]
 *
 *
 * Note:
 *
 *
 * S will be a string with length at most 12.
 * S will consist only of letters or digits.
 *
 */
class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> res;
    string out;

    dfs(S, 0, res, out);
    return res;
  }

  void dfs(const string &S, int included, vector<string> &res, string &out) {
    if (included == S.size()) {
      res.push_back(out);
      return;
    }

    char ch = S[included];
    if (isalpha(ch)) {
      out.push_back(tolower(ch));
      dfs(S, included + 1, res, out);
      out.pop_back();

      out.push_back(toupper(ch));
      dfs(S, included + 1, res, out);
      out.pop_back();
    } else {
      out.push_back(ch);
      dfs(S, included + 1, res, out);
      out.pop_back();
    }
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.letterCasePermutation("a1b2");
}
#endif
