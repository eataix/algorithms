#include <string>
#include <vector>
using namespace std;
/*
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (34.79%)
 * Total Accepted:    136K
 * Total Submissions: 391K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 */
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    vector<int> ms(128, -1);
    vector<int> mt(128, -1);

    for (int i = 0; i < s.size(); ++i) {
      if (ms[s[i]] != mt[t[i]]) {
        return false;
      }
      ms[s[i]] = mt[t[i]] = i;
    }
    return true;
  }
};
