#include <string>
using namespace std;
/*
 * [742] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (75.50%)
 * Total Accepted:    13.1K
 * Total Submissions: 17.5K
 * Testcase Example:  '"Hello"'
 *
 * Implement function ToLowerCase() that has a string parameter str, and
 * returns the same string in lowercase.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "Hello"
 * Output: "hello"
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "here"
 * Output: "here"
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "LOVELY"
 * Output: "lovely"
 *
 *
 *
 *
 *
 */
class Solution {
public:
  string toLowerCase(string str) {
    string res = str;

    for (auto it = res.begin(); it != res.end(); ++it) {
      if (*it >= 'A' && *it <= 'Z') {
        *it = *it - 'A' + 'a';
      }
    }

    return res;
  }
};
