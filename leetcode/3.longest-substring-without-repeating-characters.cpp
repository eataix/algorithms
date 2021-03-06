#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
    unordered_map<char, int> map;
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
