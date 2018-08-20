#include <cmath>
#include <string>
using namespace std;
/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (48.54%)
 * Total Accepted:    165.4K
 * Total Submissions: 340.8K
 * Testcase Example:  '"A"'
 *
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 *
 * For example:
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
  int titleToNumber(string s) {
    int res = 0;
    for (char ch : s) {
      res *= 26;
      res += ch - 'A' + 1;
    }
    return res;
  }
};
