#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
 * [291] Word Pattern II
 *
 * https://leetcode.com/problems/word-pattern-ii/description/
 *
 * algorithms
 * Hard (38.75%)
 * Total Accepted:    24.7K
 * Total Submissions: 63.8K
 * Testcase Example:  '"abab"\n"redblueredblue"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty substring in str.
 *
 * Example 1:
 *
 *
 * Input: pattern = "abab", str = "redblueredblue"
 * Output: true
 *
 * Example 2:
 *
 *
 * Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
 * Output: true
 *
 * Example 3:
 *
 *
 * Input: pattern = "aabb", str = "xyzabcxzyabc"
 * Output: false
 *
 *
 * Notes:
 * You may assume both pattern and str contains only lowercase letters.
 *
 */
class Solution {
  unordered_set<string> s;
  unordered_map<char, string> m;

public:
  bool wordPatternMatch(string pattern, string str) {
    if (pattern.empty()) {
      return str.empty();
    }
    if (m.count(pattern[0])) {
      string t = m[pattern[0]];
      if (t.size() > str.size() || str.substr(0, t.size()) != t) {
        return false;
      }
      if (wordPatternMatch(pattern.substr(1), str.substr(t.size()))) {
        return true;
      }
    } else {
      for (int i = 1; i <= str.size(); ++i) {
        auto newStr = str.substr(0, i);
        if (s.count(newStr)) {
          continue;
        }
        m[pattern[0]] = newStr;
        s.insert(newStr);
        if (wordPatternMatch(pattern.substr(1), str.substr(i))) {
          return true;
        }
        m.erase(pattern[0]);
        s.erase(newStr);
      }
    }
    return false;
  }
};
