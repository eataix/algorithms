#include <vector>
using namespace std;
/*
 * [804] Rotated Digits
 *
 * https://leetcode.com/problems/rotated-digits/description/
 *
 * algorithms
 * Easy (50.92%)
 * Total Accepted:    11.3K
 * Total Submissions: 22.1K
 * Testcase Example:  '10'
 *
 * X is a good number if after rotating each digit individually by 180 degrees,
 * we get a valid number that is different from X.  Each digit must be rotated
 * - we cannot choose to leave it alone.
 *
 * A number is valid if each digit remains a digit after rotation. 0, 1, and 8
 * rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each
 * other, and the rest of the numbers do not rotate to any other number and
 * become invalid.
 *
 * Now given a positive number N, how many numbers X from 1 to N are good?
 *
 *
 * Example:
 * Input: 10
 * Output: 4
 * Explanation:
 * There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 * Note that 1 and 10 are not good numbers, since they remain unchanged after
 * rotating.
 *
 *
 * Note:
 *
 *
 * N  will be in range [1, 10000].
 *
 *
 */
class Solution {
  bool isGood(int n) {
    bool isNewNumber = false;

    do {
      int digit = n % 10;
      switch (digit) {
      case 3:
      case 4:
      case 7:
        return false;
      case 2:
      case 5:
      case 6:
      case 9:
        isNewNumber = true;
        break;
      }
      n /= 10;
    } while (n != 0);

    return isNewNumber;
  }

public:
  int rotatedDigits(int N) {
    int res = 0;
    vector<int> dp(N + 1);
    for (int i = 0; i <= N; ++i) {
      if (i < 10) {
        switch (i) {
        case 0:
        case 1:
        case 8:
          dp[i] = 1;
          break;
        case 2:
        case 5:
        case 6:
        case 9:
          dp[i] = 2;
          res += 1;
          break;
        }
      } else {
        int a = dp[i / 10];
        int b = dp[i % 10];
        if (a == 1 && b == 1) {
          dp[i] = 1;
        } else if (a >= 1 && b >= 1) {
          dp[i] = 2;
          res += 1;
        }
      }
    }
    return res;
  }

  int rotatedDigits2(int N) {
    int goodCount = 0;
    for (int i = 1; i <= N; ++i) {
      if (isGood(i)) {
        goodCount += 1;
      }
    }
    return goodCount;
  }
};
