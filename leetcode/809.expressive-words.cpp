#include <string>
#include <vector>
using namespace std;
/*
 * [827] Expressive Words
 *
 * https://leetcode.com/problems/expressive-words/description/
 *
 * algorithms
 * Medium (37.58%)
 * Total Accepted:    4.3K
 * Total Submissions: 11.4K
 * Testcase Example:  '"heeellooo"\n["hello", "hi", "helo"]'
 *
 * Sometimes people repeat letters to represent extra feeling, such as "hello"
 * -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of adjacent letters
 * that are all the same character, and adjacent characters to the group are
 * different.  A group is extended if that group is length 3 or more, so "e"
 * and "o" would be extended in the first example, and "i" would be extended in
 * the second example.  As another example, the groups of "abbcccaaaa" would be
 * "a", "bb", "ccc", and "aaaa"; and "ccc" and "aaaa" are the extended groups
 * of that string.
 *
 * For some given string S, a query word is stretchy if it can be made to be
 * equal to S by extending some groups.  Formally, we are allowed to repeatedly
 * choose a group (as defined above) of characters c, and add some number of
 * the same character c to it so that the length of the group is 3 or more.
 * Note that we cannot extend a group of size one like "h" to a group of size
 * two like "hh" - all extensions must leave the group extended - ie., at least
 * 3 characters long.
 *
 * Given a list of query words, return the number of words that are
 * stretchy. 
 *
 *
 * Example:
 * Input:
 * S = "heeellooo"
 * words = ["hello", "hi", "helo"]
 * Output: 1
 * Explanation:
 * We can extend "e" and "o" in the word "hello" to get "heeellooo".
 * We can't extend "helo" to get "heeellooo" because the group "ll" is not
 * extended.
 *
 *
 * Notes:
 *
 *
 * 0 <= len(S) <= 100.
 * 0 <= len(words) <= 100.
 * 0 <= len(words[i]) <= 100.
 * S and all words in words consist only of lowercase letters
 *
 *
 *
 *
 */
class Solution {
public:
  int expressiveWords(string S, vector<string> &words) {
    int res = 0;

    for (auto const &w : words) {
      if (w.size() <= S.size()) {
        int i = 0;
        int j = 0;
        for (; j < S.size(); ++j) {
          if (w[i] == S[j]) {
            ++i;
          } else if (j > 0 && S[j] == S[j - 1] && j + 1 < S.size() &&
                     S[j] == S[j + 1]) {
            ++j;
          } else if (!(j > 1 && S[j] == S[j - 1] && S[j] == S[j - 2])) {
            break;
          }
        }

        if (i == w.size() && j == S.size()) {
          res += 1;
        }
      }
    }
    return res;
  }
};
