#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
/*
 * [340] Longest Substring with At Most K Distinct Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/
 *
 * algorithms
 * Hard (38.37%)
 * Total Accepted:    43.9K
 * Total Submissions: 114.4K
 * Testcase Example:  '"eceba"\n2'
 *
 *
 * Given a string, find the length of the longest substring T that contains at
 * most k distinct characters.
 *
 *
 *
 * For example,
 *
 * Given s = “eceba” and k = 2,
 *
 *
 *
 * T is "ece" which its length is 3.
 *
 */
class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> m;
    int left = 0;
    int res = 0;
    for (int right = 0; right < s.size(); ++right) {
      m[s[right]] += 1;

      while (m.size() > k) {
        if (--m[s[left]] == 0) {
          m.erase(s[left]);
        }
        left += 1;
      }

      res = max(res, right - left + 1);
    }

    return res;
  }
};
