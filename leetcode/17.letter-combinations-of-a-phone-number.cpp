#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (36.51%)
 * Total Accepted:    230.8K
 * Total Submissions: 632K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */

vector<string> dictionary{
    {},      {},      {"abc"},  {"def"}, {"ghi"},
    {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"},
};
class Solution {
  void dfs(const string &digits, int pos, string &out, vector<string> &res) {
    if (pos == digits.size()) {
      res.push_back(out);
      return;
    }
    for (char next : dictionary[digits[pos] - '0']) {
      out.push_back(next);
      dfs(digits, pos + 1, out, res);
      out.pop_back();
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    string out;
    vector<string> res;
    dfs(digits, 0, out, res);
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.letterCombinations("23");
}
#endif
