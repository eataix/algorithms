#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (33.50%)
 * Total Accepted:    103.4K
 * Total Submissions: 308.7K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * ⁠Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 *
 * Examples:
 *
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 *
 *
 *
 *
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 *
 *
 * Credits:Special thanks to @minglotus6 for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
  bool wordPattern(string pattern, string str) {
    unordered_map<char, int> m1;
    unordered_map<string, int> m2;
    istringstream in(str);
    int i = 0;
    for (string word; in >> word; ++i) {
      if (m1.find(pattern[i]) != m1.end() || m2.find(word) != m2.end()) {
        if (m1[pattern[i]] != m2[word])
          return false;
      } else {
        m1[pattern[i]] = m2[word] = i + 1;
      }
    }
    return i == pattern.size();
  }
};
