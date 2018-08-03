#include <string>
using namespace std;
/*
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (51.89%)
 * Total Accepted:    64.2K
 * Total Submissions: 123.7K
 * Testcase Example:  '"USA"'
 *
 *
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 *
 *
 *
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 *
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one
 * letter, like "Google".
 *
 * Otherwise, we define that this word doesn't use capitals in a right way.
 *
 *
 *
 * Example 1:
 *
 * Input: "USA"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "FlaG"
 * Output: False
 *
 *
 *
 * Note:
 * The input will be a non-empty word consisting of uppercase and lowercase
 * latin letters.
 *
 */
class Solution {
public:
  bool detectCapitalUse(string word) {
    int cnt = 0, n = word.size();
    for (int i = 0; i < n; ++i) {
      if (word[i] <= 'Z') {
        cnt += 1;
      }
    }
    return cnt == 0 || cnt == n || (cnt == 1 && word[0] <= 'Z');
  }
};
