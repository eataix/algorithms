#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/*
 * [159] Longest Substring with At Most Two Distinct Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/
 *
 * algorithms
 * Hard (43.32%)
 * Total Accepted:    40.4K
 * Total Submissions: 93.3K
 * Testcase Example:  '"eceba"'
 *
 * Given a string s , find the length of the longest substring t  that contains
 * at most 2 distinct characters.
 *
 * Example 1:
 *
 *
 * Input: "eceba"
 * Output: 3
 * Explanation: t is "ece" which its length is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: "ccaabbb"
 * Output: 5
 * Explanation: t is "aabbb" which its length is 5.
 *
 *
 */
class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct1(string s) {
    int left = 0;
    int right = -1;
    int res = 0;

    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) {
        continue;
      }

      if (right >= 0 && s[right] != s[i]) {
        res = max(res, i - left);
        left = right + 1;
      }

      right = i - 1;
    }

    return max(static_cast<int>(s.size()) - left, res);
  }

  int lengthOfLongestSubstringTwoDistinct(string s) {
    int res = 0;
    int left = 0;
    unordered_map<char, int> m;
    for (int right = 0; right < s.size(); ++right) {
      m[s[right]] += 1;
      while (m.size() > 2) {
        m[s[left]] -= 1;
        if (m[s[left]] == 0) {
          m.erase(s[left]);
        }
        left += 1;
      }
      res = max(res, right - left + 1);
    }

    return res;
  }
};
