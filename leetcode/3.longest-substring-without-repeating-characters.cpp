#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.70%)
 * Total Accepted:    472.8K
 * Total Submissions: 1.9M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    set<char> dictionary;

    int ans = 0, i = 0, j = 0;
    while (i < s.size() && j < s.size()) {
      if (dictionary.find(s[j]) == dictionary.cend()) {
        dictionary.insert(s[j++]);
        ans = max(ans, j - i);
      } else {
        dictionary.erase(s[i++]);
      }
    }
    return ans;
  }

  int lengthOfLongestSubstring2(string s) {
    map<char, int> map;
    int n = s.length(), ans = 0;

    for (int j = 0, i = 0; j < n; ++j) {
      if (map.find(s[j]) != map.cend()) {
        i = max(map[s[j]], i);
      }
      ans = max(ans, j - i + 1);
      map[s[j]] = j + 1;
    }
    return ans;
  }
};
