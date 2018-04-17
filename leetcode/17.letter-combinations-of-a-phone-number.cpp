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
public:
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
      return vector<string>{};
    }
    auto res = dfs(digits, 0, "");
    for (string str : res) {
      cout << str << endl;
    }
    return res;
  }

  vector<string> dfs(const string &digits, int i, string prev) {
    if (i == digits.size()) {
      return vector<string>{prev};
    } else {
      int v = digits[i] - '0';
      vector<string> ret;
      for (char ch : dictionary[v]) {
        vector<string> nextStrings = dfs(digits, i + 1, prev + ch);
        for (string str : nextStrings) {
          ret.push_back(str);
        }
      }
      return ret;
    }
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.letterCombinations("23");
}
#endif
