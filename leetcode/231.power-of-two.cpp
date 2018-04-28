#include <iostream>
using namespace std;
/*
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (40.76%)
 * Total Accepted:    170.1K
 * Total Submissions: 417.4K
 * Testcase Example:  '1'
 *
 *
 * Given an integer, write a function to determine if it is a power of two.
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
  bool isPowerOfTwo(int n) { return n > 0 && (n & n - 1) == 0; }

  bool isPowerOfTwo2(int n) {

    if (n <= 0) {
      return false;
    }

    int i = 2;
    int prev = i;
    while (true) {
      int i = prev * 2;
      if (i / 2 != prev) {
        break;
      } else {
        prev = i;
      }
    }
    cout << prev << endl;

    return prev % n == 0;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.isPowerOfTwo(16) << endl;
}
#endif
