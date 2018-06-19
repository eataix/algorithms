#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
/*
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (41.78%)
 * Total Accepted:    59.8K
 * Total Submissions: 143.1K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */
class Solution {
public:
  string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;

    string res;
    while (i >= 0 || j >= 0 || carry > 0) {
      int firstOp = i >= 0 ? (num1[i] - '0') : 0;
      int secondOp = j >= 0 ? (num2[j] - '0') : 0;

      int sum = firstOp + secondOp + carry;
      carry = sum / 10;
      int newDigit = sum % 10;
      res += to_string(newDigit);

      i -= 1;
      j -= 1;
    }

    reverse(res.begin(), res.end());
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.addStrings("1230", "1") << endl;
  cout << sol.addStrings("99", "1") << endl;
}
#endif
