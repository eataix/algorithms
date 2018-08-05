#include <string>
#include <vector>
using namespace std;
/*
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (25.36%)
 * Total Accepted:    85.8K
 * Total Submissions: 338.4K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * Example:
 *
 *
 * Input: "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 *
 *
 *
 *
https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/PalindromePartition.java<Paste>

https://leetcode.com/problems/palindrome-partitioning-ii/discuss/42213/Easiest-Java-DP-Solution-(97.36)
 */
class Solution {
public:
  int minCut(string s) {
    if (s.empty()) {
      return 0;
    }

    int len = s.size();
    vector<vector<bool>> isPal(len, vector<bool>(len, false));
    vector<int> cuts(len);

    for (int i = 0; i < len; ++i) {
      int minV = i;
      for (int j = 0; j <= i; ++j) {
        if (s[i] == s[j] && (i - 1 < j + 1 || isPal[i - 1][j + 1])) {
          isPal[i][j] = true;
          minV = min(minV, j == 0 ? 0 : 1 + cuts[j - 1]);
        }
      }
      cuts[i] = minV;
    }
    return cuts.back();
  }
};
