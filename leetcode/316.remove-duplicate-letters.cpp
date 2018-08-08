#include <string>
#include <vector>
using namespace std;
/*
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (30.58%)
 * Total Accepted:    41.1K
 * Total Submissions: 134.4K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string which contains only lowercase letters, remove duplicate
 * letters so that every letter appear once and only once. You must make sure
 * your result is the smallest in lexicographical order among all possible
 * results.
 *
 * Example 1:
 *
 *
 * Input: "bcabc"
 * Output: "abc"
 *
 *
 * Example 2:
 *
 *
 * Input: "cbacdcbc"
 * Output: "acdb"
 *
 *
 * https://www.hrwhisper.me/leetcode-remove-duplicate-letters/
 */
class Solution {
public:
  string removeDuplicateLetters(string s) {
    vector<int> count(256, 0); // number of occurrences of each character
    vector<bool> included(256, false); // in result

    for (char ch : s) {
      count[ch] += 1;
    }

    string res = " ";

    for (char ch : s) {
      count[ch] -= 1;
      if (!included[ch]) {
        // Remove all characters that are in the result, provided that the
        // characters have larger order and we can use the characters latter
        while (ch < res.back() && count[res.back()] > 0) {
          included[res.back()] = false;
          res.pop_back();
        }
        res += ch;
        included[ch] = true;
      }
    }

    return res.substr(1);
  }
};
