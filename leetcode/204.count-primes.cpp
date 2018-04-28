#include <algorithm>
#include <vector>
using namespace std;
/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (26.50%)
 * Total Accepted:    154.4K
 * Total Submissions: 582.6K
 * Testcase Example:  '0'
 *
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
  int countPrimes(int n) {
    vector<bool> isPrime(n + 1, true);

    for (int i = 2; i <= n; ++i) {
      if (isPrime[i]) {
        for (int p = 2; i * p <= n; ++p) {
          isPrime[i * p] = false;
        }
      }
    }
    int count = 0;
    for (int i = 2; i < n; ++i) {
      if (isPrime[i]) {
        count += 1;
      }
    }
    return count;
  }
};
