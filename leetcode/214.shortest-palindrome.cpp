#include <string>
#include <vector>
using namespace std;
/*
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (25.53%)
 * Total Accepted:    57.1K
 * Total Submissions: 223.7K
 * Testcase Example:  '"aacecaaa"'
 *
 * Given a string s, you are allowed to convert it to a palindrome by adding
 * characters in front of it. Find and return the shortest palindrome you can
 * find by performing this transformation.
 *
 * Example 1:
 *
 *
 * Input: "aacecaaa"
 * Output: "aaacecaaa"
 *
 *
 * Example 2:
 *
 *
 * Input: "abcd"
 * Output: "dcbabcd"
 *
 */
class Solution {
public:
  string shortestPalindrome(string s) {
    auto N = s.size();
    auto rev = s;
    reverse(rev.begin(), rev.end());
    auto newS = s + '#' + rev;
    auto newN = newS.size();

    vector<int> f(newN, 0);

    for (int i = 1; i < newN; ++i) {
      int t = f[i - 1];
      while (t > 0 && newS[i] != newS[t]) {
        t = f[t - 1];
      }

      if (newS[i] == newS[t]) {
        t += 1;
      }

      f[i] = t;
    }

    return rev.substr(0, N - f.back()) + s;
  }
};
