/*
 * [757] Pyramid Transition Matrix
 *
 * https://leetcode.com/problems/pyramid-transition-matrix/description/
 *
 * algorithms
 * Medium (47.85%)
 * Total Accepted:    7.3K
 * Total Submissions: 15.2K
 * Testcase Example:  '"ABC"\n["ABD","BCE","DEF","FFF"]'
 *
 *
 * We are stacking blocks to form a pyramid.  Each block has a color which is a
 * one letter string, like `'Z'`.
 *
 * For every block of color `C` we place not in the bottom row, we are placing
 * it on top of a left block of color `A` and right block of color `B`.  We are
 * allowed to place the block there only if `(A, B, C)` is an allowed triple.
 *
 * We start with a bottom row of bottom, represented as a single string.  We
 * also start with a list of allowed triples allowed.  Each allowed triple is
 * represented as a string of length 3.
 *
 * Return true if we can build the pyramid all the way to the top, otherwise
 * false.
 *
 *
 * Example 1:
 *
 * Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
 * Output: true
 * Explanation:
 * We can stack the pyramid like this:
 * ⁠   A
 * ⁠  / \
 * ⁠ D   E
 * ⁠/ \ / \
 * X   Y   Z
 *
 * This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are
 * allowed triples.
 *
 *
 *
 * Example 2:
 *
 * Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
 * Output: false
 * Explanation:
 * We can't stack the pyramid to the top.
 * Note that there could be allowed triples (A, B, C) and (A, B, D) with C !=
 * D.
 *
 *
 *
 * Note:
 *
 * bottom will be a string with length in range [2, 8].
 * allowed will have length in range [0, 200].
 * Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E',
 * 'F', 'G'}.
 *
 *
 */
class Solution {
public:
  bool pyramidTransition(string bottom, vector<string> &allowed) {
    int n = bottom.size();
    vector<vector<vector<bool>>> dp(
        n, vector<vector<bool>>(n, vector<bool>(7, false)));
    unordered_map<char, unordered_set<string>> m;
    for (string str : allowed) {
      m[str[2]].insert(str.substr(0, 2));
    }
    for (int i = 0; i < n; ++i) {
      dp[n - 1][i][bottom[i] - 'A'] = true;
    }
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        for (char ch = 'A'; ch <= 'G'; ++ch) {
          if (!m.count(ch))
            continue;
          for (string str : m[ch]) {
            if (dp[i + 1][j][str[0] - 'A'] && dp[i + 1][j + 1][str[1] - 'A']) {
              dp[i][j][ch - 'A'] = true;
            }
          }
        }
      }
    }
    for (int i = 0; i < 7; ++i) {
      if (dp[0][0][i])
        return true;
    }
    return false;
  }
};
