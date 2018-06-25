#include <algorithm>
#include <stack>
#include <string>
using namespace std;
/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (34.04%)
 * Total Accepted:    197K
 * Total Submissions: 578.8K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 */
class Solution {
public:
  string addBinary(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry) {
      int op1 = i >= 0 ? a[i] - '0' : 0;
      int op2 = j >= 0 ? b[j] - '0' : 0;

      int sum = op1 + op2 + carry;
      carry = sum >= 2;
      res += '0' + (sum & 1);

      i -= 1;
      j -= 1;
    }

    reverse(res.begin(), res.end());
    return res;
  }
};

#ifdef DEBUG
#include <iostream>
int main() {
  Solution sol;
  cout << sol.addBinary("1", "111") << endl;
}
#endif
