#include <iostream>
#include <string>
using namespace std;
/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (36.77%)
 * Total Accepted:    188.7K
 * Total Submissions: 513K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 *
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 *
 *
 * Given an integer n, generate the nth term of the count-and-say sequence.
 *
 *
 *
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 *
 *
 * Example 1:
 *
 * Input: 1
 * Output: "1"
 *
 *
 *
 * Example 2:
 *
 * Input: 4
 * Output: "1211"
 *
 *
 */
class Solution {
public:
  string countAndSay(int n) {
    if (n == 1) {
      return "1";
    }
    if (n == 2) {
      return "11";
    }
    string prevStr = "11";
    for (int i = 3; i <= n; ++i) {
      string currStr = "";
      char prevChar = prevStr[0];
      int count = 1;
      for (int j = 1; j < prevStr.size(); ++j) {
        char currChar = prevStr[j];
        if (currChar != prevChar) {
          currStr += to_string(count);
          currStr += prevChar;
          count = 1;
          prevChar = currChar;
        } else {
          count += 1;
        }
      }
      currStr += to_string(count);
      currStr += prevChar;
      prevStr = currStr;
    }
    return prevStr;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.countAndSay(4) << endl;
}
#endif