/*
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (42.59%)
 * Total Accepted:    21.9K
 * Total Submissions: 51.3K
 * Testcase Example:  '"ABAB"\n2'
 *
 * Given a string that consists of only uppercase English letters, you can
 * replace any letter in the string with another letter at most k times. Find
 * the length of a longest substring containing all repeating letters you can
 * get after performing the above operations.
 *
 * Note:
 * Both the string's length and k will not exceed 104.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * s = "ABAB", k = 2
 *
 * Output:
 * 4
 *
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s = "AABABBA", k = 1
 *
 * Output:
 * 4
 *
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 *
 *
 */
class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();
    vector<int> count(26, 0);

    int left = 0;
    int maxCount = 0;
    int maxLen = 0;
    for (int right = 0; right < n; ++right) {
      maxCount = max(maxCount, ++count[s[right] - 'A']);
      while (right - left + 1 - maxCount > k) {
        count[s[left] - 'A'] -= 1;
        left += 1;
      }
      maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};
