#include <string>
#include <vector>
using namespace std;
/*
 * [320] Generalized Abbreviation
 *
 * https://leetcode.com/problems/generalized-abbreviation/description/
 *
 * algorithms
 * Medium (46.68%)
 * Total Accepted:    31.1K
 * Total Submissions: 66.7K
 * Testcase Example:  '"word"'
 *
 * Write a function to generate the generalized abbreviations of a word. 
 *
 * Note: The order of the output does not matter.
 *
 * Example:
 *
 *
 * Input: "word"
 * Output:
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d",
 * "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 *
 *
 *
 *
 */
class Solution {
  void helper(const string &word, string out, vector<string> &res, int included,
              int count) {
    if (included == word.size()) {
      if (count > 0) {
        out += to_string(count);
      }
      res.push_back(out);
      return;
    }

    helper(word, out, res, included + 1, count + 1);
    helper(word, out + (count > 0 ? to_string(count) : "") + word[included],
           res, included + 1, 0);
  }

public:
  vector<string> generateAbbreviations(string word) {
    string out;
    vector<string> res;
    helper(word, out, res, 0, 0);
    return res;
  }
};
