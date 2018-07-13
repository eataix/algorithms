/*
 * [897] Prime Palindrome
 *
 * https://leetcode.com/problems/prime-palindrome/description/
 *
 * algorithms
 * Medium (16.85%)
 * Total Accepted:    2.2K
 * Total Submissions: 12.8K
 * Testcase Example:  '6'
 *
 * Find the smallest prime palindrome greater than or equal to N.
 *
 * Recall that a number is prime if it's only divisors are 1 and itself, and it
 * is greater than 1. 
 *
 * For example, 2,3,5,7,11 and 13 are primes.
 *
 * Recall that a number is a palindrome if it reads the same from left to right
 * as it does from right to left. 
 *
 * For example, 12321 is a palindrome.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 6
 * Output: 7
 *
 *
 *
 * Example 2:
 *
 *
 * Input: 8
 * Output: 11
 *
 *
 *
 * Example 3:
 *
 *
 * Input: 13
 * Output: 101
 *
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= N <= 10^8
 * The answer is guaranteed to exist and be less than 2 * 10^8.
 *
 *
 */
class Solution {
  bool isPrime(int N) {
    if (N < 2) {
      return false;
    }

    for (int d = 2; d * d <= N; ++d) {
      if (N % d == 0) {
        return false;
      }
    }

    return true;
  }

  int reverse(int N) {
    int ans = 0;

    while (N > 0) {
      ans *= 10;
      ans += N % 10;
      N /= 10;
    }

    return ans;
  }

public:
  int primePalindrome(int N) {
    while (true) {
      if (N == reverse(N) && isPrime(N)) {
        return N;
      }
      N += 1;

      if (10000000 < N && N < 100000000) {
        N = 100000000;
      }
    }
  }
};
