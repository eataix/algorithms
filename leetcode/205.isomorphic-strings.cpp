#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
    unordered_map<char, char> map;
    unordered_set<char> mappedChars;

    for (int i = 0; i < s.size(); ++i) {
      char ch1 = s[i];
      char ch2 = t[i];

      if (map.find(ch1) != map.cend()) {
        if (map[ch1] != ch2) {
          cout << map[ch1] << " != " << ch2 << endl;
          return false;
        }
      } else {
        if (mappedChars.find(ch2) != mappedChars.cend()) {
          cout << ch2 << " is being remapped" << endl;
          return false;
        }
        map[ch1] = ch2;
        mappedChars.insert(ch2);
      }
    }
    return true;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.isIsomorphic("egg", "add") << endl;
}
#endif
