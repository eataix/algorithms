#include <string>
#include <vector>
using namespace std;
/*
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (22.84%)
 * Total Accepted:    60.6K
 * Total Submissions: 265.1K
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer to its english words representation. Given
 * input is guaranteed to be less than 231 - 1.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: "One Hundred Twenty Three"
 *
 *
 * Example 2:
 *
 *
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 *
 * Example 3:
 *
 *
 * Input: 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 *
 *
 */
const vector<string> v = {"Thousand", "Million", "Billion"};
const vector<string> v1 = {"",        "One",       "Two",      "Three",
                           "Four",    "Five",      "Six",      "Seven",
                           "Eight",   "Nine",      "Ten",      "Eleven",
                           "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                           "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const vector<string> v2 = {"",      "",      "Twenty",  "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

class Solution {
public:
  string numberToWords(int num) {
    string res = convertHundred(num % 1000);
    for (int i = 0; i < 3; ++i) {
      num /= 1000;
      if (num % 1000 > 0) {
        res = convertHundred(num % 1000) + " " + v[i] + " " + res;
      }
    }

    while (res.back() == ' ') {
      res.pop_back();
    }
    return res.empty() ? "Zero" : res;
  }

  string convertHundred(int num) {
    string res;
    int a = num / 100, b = num % 100, c = num % 10;

    if (b < 20) {
      res = v1[b];
    } else {
      res = v2[b / 10] + (c > 0 ? " " + v1[c] : "");
    }

    if (a > 0) {
      res = v1[a] + " Hundred" + (b > 0 ? " " + res : "");
    }
    return res;
  }
};
