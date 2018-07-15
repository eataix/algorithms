#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (35.80%)
 * Total Accepted:    27.9K
 * Total Submissions: 77.9K
 * Testcase Example:  '"aaabb"\n3'
 *
 *
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 *
 *
 * Example 1:
 *
 * Input:
 * s = "aaabb", k = 3
 *
 * Output:
 * 3
 *
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s = "ababbc", k = 2
 *
 * Output:
 * 5
 *
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
 *
 *
 */
class Solution {
public:
  int longestSubstring(string s, int k) {
    int maxLen = 0;
    for (int first = 0; first + k <= s.size();) {
      vector<int> count(26, 0);

      int mask = 0;
      int maxLast = first;
      for (int last = first; last < s.size(); ++last) {
        int i = s[last] - 'a';
        count[i] += 1;
        if (count[i] < k) {
          mask |= 1 << i;
        } else {
          mask &= ~(1 << i);
        }

        if (mask == 0) {
          maxLen = max(maxLen, last - first + 1);
          maxLast = last;
        }
      }
      first = maxLast + 1;
    }
    return maxLen;
  }
};
