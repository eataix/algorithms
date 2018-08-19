#include <string>
using namespace std;
/*
 * [686] Repeated String Match
 *
 * https://leetcode.com/problems/repeated-string-match/description/
 *
 * algorithms
 * Easy (31.69%)
 * Total Accepted:    32.2K
 * Total Submissions: 101.6K
 * Testcase Example:  '"abcd"\n"cdabcdab"'
 *
 * Given two strings A and B, find the minimum number of times A has to be
 * repeated such that B is a substring of it. If no such solution, return -1.
 *
 *
 * For example, with A = "abcd" and B = "cdabcdab".
 *
 *
 * Return 3, because by repeating A three times (“abcdabcdabcd”), B is a
 * substring of it; and B is not a substring of A repeated two times
 * ("abcdabcd").
 *
 *
 * Note:
 * The length of A and B will be between 1 and 10000.
 *
 */
class Solution {
public:
  int repeatedStringMatch(string A, string B) {
    auto newA = A;
    while (newA.size() < B.size()) {
      newA += A;
    }

    if (newA.find(B) != string::npos) {
      return newA.size() / A.size();
    }

    newA += A;
    if (newA.find(B) != string::npos) {
      return newA.size() / A.size();
    } else {
      return -1;
    }
  }
};
