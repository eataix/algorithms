#include <string>
using namespace std;
/*
 * [812] Rotate String
 *
 * https://leetcode.com/problems/rotate-string/description/
 *
 * algorithms
 * Easy (50.41%)
 * Total Accepted:    16.9K
 * Total Submissions: 33.5K
 * Testcase Example:  '"abcde"\n"cdeab"'
 *
 * We are given two strings, A and B.
 *
 * A shift on A consists of taking string A and moving the leftmost character
 * to the rightmost position. For example, if A = 'abcde', then it will be
 * 'bcdea' after one shift on A. Return True if and only if A can become B
 * after some number of shifts on A.
 *
 *
 * Example 1:
 * Input: A = 'abcde', B = 'cdeab'
 * Output: true
 *
 * Example 2:
 * Input: A = 'abcde', B = 'abced'
 * Output: false
 *
 *
 * Note:
 *
 *
 * A and B will have length at most 100.
 *
 *
 */
class Solution {
public:
  bool rotateString(string A, string B) {
    return A.size() == B.size() && (A + A).find(B) != string::npos;
  }
};