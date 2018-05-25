#include <iostream>
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
  string minWindow(const string &s, const string &t) {
    if (t.size() > s.size()) {
      return "";
    }
    vector<int> sm(256, 0);
    vector<int> tm(256, 0);

    for (auto const &ch : t) {
      tm[ch] += 1;
    }

    int bestStart = -1;
    int start = 0;
    int count = 0;
    int minLen = s.size() + 1;
    for (int end = 0; end < s.size(); ++end) {
      char ch = s[end];
      if (tm[ch] > 0) {
        sm[ch] += 1;
        if (sm[ch] <= tm[ch]) {
          count += 1;
        }

        while (count == t.size()) {
          // Compare the size of the current window against the previously
          // seen optimal one
          if (end - start + 1 < minLen) {
            minLen = end - start + 1;
            bestStart = start;
          }

          // We now try to shrink the window size by one, i.e., move the start
          // to the right by one.
          if (tm[s[start]] > 0) {
            // s[start] is about to be removed
            sm[s[start]] -= 1;
            // If the removal results in an insufficient number of a char,
            // reduce teh count by one.
            if (sm[s[start]] < tm[s[start]]) {
              count -= 1;
            }
          } else {
            // Do nothing
          }

          start += 1;
        }
      } else {
        // ch is not relevant, just pass
      }
    }

    return bestStart == -1 ? "" : s.substr(bestStart, minLen);
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << "'" << sol.minWindow("ADOBECODEBANC", "ABC") << "'" << endl;
  cout << "'" << sol.minWindow("A", "AA") << "'" << endl;
  cout << "'" << sol.minWindow("a", "b") << "'" << endl;
}
#endif
