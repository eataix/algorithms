#include <string>
#include <vector>
using namespace std;
/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (26.87%)
 * Total Accepted:    150K
 * Total Submissions: 554.3K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * Example:
 *
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 *
 *
 * Note:
 *
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 *
 *
 */
class Solution {
public:
  string minWindow(string s, string t) {
    if (t.size() > s.size()) {
      return "";
    }

    string res;
    int minLen = s.size() + 1;

    vector<int> tm(256, 0);
    for (const auto &ch : t) {
      tm[ch] += 1;
    }

    vector<int> sm(256, 0);
    int left = 0;
    int count = 0;
    for (int right = 0; right < s.size(); ++right) {
      if (tm[s[right]] > 0) {
        sm[s[right]] += 1;
        if (sm[s[right]] <= tm[s[right]]) {
          count += 1;
        }

        while (count == t.size()) {
          int currLen = right - left + 1;
          if (currLen < minLen) {
            minLen = currLen;
            res = s.substr(left, minLen);
          }
          if (tm[s[left]] > 0) {
            sm[s[left]] -= 1;
            if (sm[s[left]] < tm[s[left]]) {
              count -= 1;
            }
          }
          left += 1;
        }
      }
    }

    return res;
  }
};
