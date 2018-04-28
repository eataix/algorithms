#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.71%)
 * Total Accepted:    476.3K
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
#ifdef DEBUG
    cout << s << endl;
#endif
    int maxV = 0;
    unordered_map<char, int> window;
    int start = 0;
    for (int i = 0; i < s.size(); ++i) {
      char ch = s[i];
      if (window.find(ch) != window.cend()) {
        start = max(start, window[ch] + 1);
      }
      window[ch] = i;
      maxV = max(maxV, i - start + 1);
#ifdef DEBUG
      cout << "Update to " << start + 1 << " " << i + 1 << " " << maxV << endl;
#endif
    }

    return maxV;
  }
};

#ifdef DEBUG
int main() {
  string s1{"abcabcbb"};
  string s2{"bbbbb"};
  string s3{"pwwkew"};
  string s4{"abba"};
  Solution sol;
  cout << sol.lengthOfLongestSubstring(s1) << endl;
  cout << sol.lengthOfLongestSubstring(s2) << endl;
  cout << sol.lengthOfLongestSubstring(s3) << endl;
  cout << sol.lengthOfLongestSubstring(s4) << endl;
}
#endif
