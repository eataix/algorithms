#include <string>
#include <unordered_set>
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
    int required = unordered_set<char>(t.cbegin(), t.cend()).size();
    vector<int> tCount(128, 0);
    for (char ch : t) {
      tCount[ch] += 1;
    }

    vector<int> sCount(128, 0);

    int left = 0;
    int count = 0;
    int res = numeric_limits<int>::max();
    int minStart = -1;
    for (int right = 0; right < s.size(); ++right) {
      char ch = s[right];
      if (tCount[ch] > 0) {

        sCount[ch] += 1;
        if (sCount[ch] == tCount[ch]) {
          count += 1;
        }

        while (count == required) {
          auto len = right - left + 1;
          if (len < res) {
            minStart = left;
            res = len;
          }
          if (tCount[s[left]] > 0) {
            sCount[s[left]] -= 1;
            if (sCount[s[left]] < tCount[s[left]]) {
              count -= 1;
            }
          }
          left += 1;
        }
      }
    }
    return minStart == -1 ? "" : s.substr(minStart, res);
  }
};
