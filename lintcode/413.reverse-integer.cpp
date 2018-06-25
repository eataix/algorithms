#include <algorithm>
using namespace std;
class Solution {
public:
  /**
   * @param n: the integer to be reversed
   * @return: the reversed integer
   */
  int reverseInteger(int n) {
    if (n == 0) {
      return 0;
    } else if (n < 0) {
      return -reverseInteger(abs(n));
    } else {
      int res = 0;

      while (n > 0) {
        res = res * 10 + n % 10;
        n /= 10;
      }
      return res;
    }
  }
};
