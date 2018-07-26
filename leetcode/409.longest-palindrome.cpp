#include <string>
#include <vector>
using namespace std;
/*
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (46.19%)
 * Total Accepted:    70.3K
 * Total Submissions: 152.2K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 *
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 *
 * Note:
 * Assume the length of given string will not exceed 1,010.
 *
 *
 * Example:
 *
 * Input:
 * "abccccdd"
 *
 * Output:
 * 7
 *
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 *
 *
 */
class Solution {
public:
  int longestPalindrome(string s) {
    vector<int> count(128, 0);
    for (auto ch : s) {
      count[ch] += 1;
    }

    int res = 0;
    for (int c : count) {
      res += c / 2 * 2;

      if (res % 2 == 0 && c % 2 == 1) {
        res += 1;
      }
    }
    return res;
  }
};
