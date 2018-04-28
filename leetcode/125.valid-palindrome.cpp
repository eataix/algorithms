#include <iostream>
#include <string>
using namespace std;
/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (27.13%)
 * Total Accepted:    224.8K
 * Total Submissions: 828.7K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "race a car"
 * Output: false
 *
 *
 */
class Solution {
public:
  bool isPalindrome(string s) {
    if (s.size() <= 1) {
      return true;
    }

    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
      if (!isalnum(s[i])) {
        i += 1;
        continue;
      }
      if (!isalnum(s[j])) {
        j -= 1;
        continue;
      }
      if (tolower(s[i]) == tolower(s[j])) {
        i += 1;
        j -= 1;
      } else {
        cout << "i: " << i << " j: " << j << endl;
        cout << "s[i]: " << s[i] << " s[j]: " << s[j] << endl;
        return false;
      }
    }
    return true;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
}
#endif
