#include <iostream>
#include <map>
#include <string>
using namespace std;
/*
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (47.49%)
 * Total Accepted:    209.7K
 * Total Submissions: 441.4K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, write a function to determine if t is an anagram
 * of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 *
 */
class Solution {
public:
  bool isAnagram(string s, string t) {
    map<char, int> dictionary;
    for (char ch : s) {
      dictionary[ch] += 1;
    }
#ifdef DEBUG
    for (auto entry : dictionary) {
      cout << entry.first << " " << entry.second << endl;
    }
#endif
    for (char ch : t) {
      dictionary[ch] -= 1;
    }
#ifdef DEBUG
    for (auto entry : dictionary) {
      cout << entry.first << " " << entry.second << endl;
    }
#endif

    for (auto entry : dictionary) {
      if (entry.second != 0) {
        return false;
      }
    }
    return true;
  }
};
