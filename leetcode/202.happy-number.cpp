#include <cmath>
#include <iostream>
#include <unordered_set>
using namespace std;
/*
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (41.57%)
 * Total Accepted:    159.7K
 * Total Submissions: 384.2K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 *
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 *
 *
 * Credits:
 * Special thanks to @mithmatt and @ts for adding this problem and creating all
 * test cases.
 *
 */
class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> seen;
    seen.insert(n);
    for (;;) {
      if (n == 1) {
        return true;
      } else {
        n = convert(n);
        if (seen.find(n) != seen.cend()) {
          return false;
        } else {
          seen.insert(n);
        }
      }
    }
  }

  int convert(int n) {
    int res = 0;
    do {
      int i = n % 10;
      res += pow(i, 2);
      n /= 10;
    } while (n > 0);
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.isHappy(19) << endl;
  cout << sol.isHappy(82) << endl;
  cout << sol.isHappy(68) << endl;
  cout << sol.isHappy(100) << endl;
}
#endif
