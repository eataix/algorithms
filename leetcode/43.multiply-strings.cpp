#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (28.14%)
 * Total Accepted:    140.2K
 * Total Submissions: 498.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Example 1:
 *
 *
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 *
 * Example 2:
 *
 *
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Note:
 *
 *
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */
class Solution {
public:
  string multiply(const string &num1, const string &num2) {
    vector<int> pos(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; i >= 0; --i) {
      for (int j = num2.size() - 1; j >= 0; --j) {
        int mul = (num1[i] - '0') * (num2[j] - '0');
        int p1 = i + j;
        int p2 = i + j + 1;
        int sum = mul + pos[p2];

        pos[p1] += sum / 10;
        pos[p2] = sum % 10;
      }
    }

    string res;
    for (int p : pos) {
      cout << p << endl;
      if (!res.empty() || p > 0) {
        res += to_string(p);
      }
    }
    return res.empty() ? "0" : res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.multiply("123", "456") << endl;
}
#endif
