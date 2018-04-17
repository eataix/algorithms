#include <map>
#include <string>
using namespace std;
/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.12%)
 * Total Accepted:    117.7K
 * Total Submissions: 249.8K
 * Testcase Example:  '"leetcode"'
 *
 *
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 *
 *
 *
 *
 * Note: You may assume the string contain only lowercase letters.
 *
 */
class Solution {
public:
  int firstUniqChar(string s) {
    map<char, int> dictionary;
    for (char ch : s) {
      dictionary[ch] += 1;
    }
    for (int i = 0; i < s.size(); ++i) {
      if (dictionary[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};
