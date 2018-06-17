#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
/*
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (18.24%)
 * Total Accepted:    66.7K
 * Total Submissions: 365.8K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 *
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 *
 * Example 1:
 *
 *
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 *
 *
 * Example 2:
 *
 *
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 *
 * Example 3:
 *
 *
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 *
 *
 */
class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    bool b1 = numerator >= 0;
    bool b2 = denominator >= 0;

    long long dividend = abs(static_cast<long long>(numerator));
    long long divisor = abs(static_cast<long long>(denominator));

    long long quo = dividend / divisor;
    long long rem = dividend % divisor;

    string res = to_string(quo);
    if (b1 ^ b2 && (quo > 0 || rem > 0)) {
      res = '-' + res;
    }

    if (rem == 0) {
      return res;
    }

    res += '.';

    string s;
    unordered_map<long long, int> m;

    for (int pos = 0; rem != 0; pos += 1) {
      if (m.find(rem) != m.cend()) {
        s.insert(m[rem], "(");
        s += ")";
        return res + s;
      }

      m[rem] = pos;
      s += to_string((rem * 10) / divisor);
      rem = (rem * 10) % divisor;
    }

    return res + s;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.fractionToDecimal(1, 2) << endl;
  cout << sol.fractionToDecimal(2, 1) << endl;
  cout << sol.fractionToDecimal(2, 3) << endl;
}
#endif
