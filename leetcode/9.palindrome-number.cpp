/*
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (35.77%)
 * Total Accepted:    319.9K
 * Total Submissions: 894.3K
 * Testcase Example:  '-2147483648'
 *
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 * click to show spoilers.
 *
 * Some hints:
 *
 * Could negative integers be palindromes? (ie, -1)
 *
 * If you are thinking of converting the integer to string, note the
 * restriction of using extra space.
 *
 * You could also try reversing an integer. However, if you have solved the
 * problem "Reverse Integer", you know that the reversed integer might
 * overflow. How would you handle such case?
 *
 * There is a more generic way of solving this problem.
 *
 *
 */
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    int division = 1;
    while (x / division >= 10) {
      division *= 10;
    }

    while (x != 0) {
      int l = x / division;
      int r = x % 10;
      if (l != r) {
        return false;
      }
      x = (x % division) / 10;
      division /= 100;
    }
    return true;
  }
};
