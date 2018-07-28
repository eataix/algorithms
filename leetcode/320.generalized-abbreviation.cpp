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

#include <cmath>
using namespace std;
class Solution {
public:
  vector<string> generateAbbreviations(string word) {
    int len = word.size();
    vector<string> res;
    for (int i = 0; i < pow(2, len); ++i) { // 00, 01, 10, 11
      string st;
      for (int j = 0; j < word.size(); ++j) {
        if ((1 << j) & i) {
          st += word[j];
        } else {
          st += '.';
        }
      }
      int count = 0;
      string st2;
      for (char ch : st) {
        if (ch == '.') {
          count += 1;
        } else {
          if (count > 0) {
            st2 += to_string(count);
            count = 0;
          }
          st2 += ch;
        }
      }
      if (count > 0) {
        st2 += to_string(count);
      }
      res.push_back(st2);
    }
    return res;
  }
};
