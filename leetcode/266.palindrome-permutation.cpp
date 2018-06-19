#include <iostream>
#include <unordered_set>
using namespace std;
/*
 * [266] Palindrome Permutation
 *
 * https://leetcode.com/problems/palindrome-permutation/description/
 *
 * algorithms
 * Easy (58.31%)
 * Total Accepted:    47.6K
 * Total Submissions: 81.5K
 * Testcase Example:  '"code"'
 *
 * Given a string, determine if a permutation of the string could form a
 * palindrome.
 *
 * Example 1:
 *
 *
 * Input: "code"
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: "aab"
 * Output: true
 *
 * Example 3:
 *
 *
 * Input: "carerac"
 * Output: true
 *
 */
class Solution {
public:
  bool canPermutePalindrome(const string &str) {
    unordered_set<char> s;
    for (char ch : str) {
      if (s.count(ch)) {
        s.erase(ch);
      } else {
        s.insert(ch);
      }
    }
    return s.size() <= 1;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;

  cout << sol.canPermutePalindrome("code") << endl;
  cout << sol.canPermutePalindrome("aab") << endl;
  cout << sol.canPermutePalindrome("carerac") << endl;
}
#endif
