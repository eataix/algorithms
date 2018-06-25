#include <iostream>
#include <string>
using namespace std;

/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (27.29%)
 * Total Accepted:    204.8K
 * Total Submissions: 750.3K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 *
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 *
 *
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 *
 *
 * string convert(string text, int nRows);
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 *
 *
 */
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }

    int cycleLen = 2 * numRows - 2;
    string res;

    for (int row = 0; row < numRows; ++row) {
      if (row == 0) {
        for (int k = 0, idx; (idx = k * cycleLen) < s.size(); ++k) {
          res += s[idx];
        }
      } else if (row == numRows - 1) {
        for (int k = 0, idx; (idx = k * cycleLen + numRows - 1) < s.size();
             ++k) {
          res += s[idx];
        }
      } else {
        for (int k = 0, idx; (idx = k * cycleLen + row) < s.size(); ++k) {
          res += s[idx];
          if ((idx = (k + 1) * cycleLen - row) < s.size()) {
            res += s[idx];
          }
        }
      }
    }
    return res;
  }

  string convert2(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    string res;
    int step = 2 * numRows - 2;
    for (int i = 0; i < numRows; ++i) {
      if (i == 0 || i == numRows - 1) {
        for (int j = i; j < s.size(); j += step) {
          res += s[j];
        }
      } else {
        int j = i;
        bool flag = true;
        int step1 = 2 * (numRows - 1 - i);
        int step2 = step - step1;
        while (j < s.size()) {
          res += s[j];
          if (flag) {
            j += step1;
          } else {
            j += step2;
          }
          flag = !flag;
        }
      }
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.convert("PAYPALISHIRING", 3) << endl;
  cout << "PAHNAPLSIIGYIR" << endl;
  cout << sol.convert("PAYPALISHIRING", 4) << endl;
  cout << "PINALSIGYAHRPI" << endl;
}
#endif
