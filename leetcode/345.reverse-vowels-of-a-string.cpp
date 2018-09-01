#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
using namespace std;
/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (39.26%)
 * Total Accepted:    106.6K
 * Total Submissions: 271.5K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 *
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 *
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 *
 *
 *
 * Note:
 * The vowels does not include the letter "y".
 *
 */

unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

class Solution {
public:
  string reverseVowels(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      while (left < right && !vowels.count(s[left])) {
        left += 1;
      }

      while (left < right && !vowels.count(s[right])) {
        right -= 1;
      }

      if (left >= right) {
        break;
      }

      swap(s[left], s[right]);
      left += 1;
      right -= 1;
    }
    return s;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.reverseVowels(string{"hello"}) << endl;
  cout << sol.reverseVowels(string{"leetcode"}) << endl;
}
#endif
