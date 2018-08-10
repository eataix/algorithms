#include <vector>
using namespace std;
/*
 * [372] Super Pow
 *
 * https://leetcode.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (34.86%)
 * Total Accepted:    22.4K
 * Total Submissions: 64.3K
 * Testcase Example:  '2\n[3]'
 *
 *
 * Your task is to calculate ab mod 1337 where a is a positive integer and b is
 * an extremely large positive integer given in the form of an array.
 *
 *
 * Example1:
 *
 * a = 2
 * b = [3]
 *
 * Result: 8
 *
 *
 *
 * Example2:
 *
 * a = 2
 * b = [1,0]
 *
 * Result: 1024
 *
 *
 *
 * Credits:Special thanks to @Stomach_ache for adding this problem and creating
 * all test cases.
 */

const static int mod = 1337;
class Solution {
  int powmod(int a, int k) // a^k mod 1337 where 0 <= k <= 10
  {
    a %= mod;
    int result = 1;
    for (int i = 0; i < k; ++i) {
      result = (result * a) % mod;
    }
    return result;
  }

public:
  int superPow(int a, vector<int> &b) {
    if (b.empty()) {
      return 1;
    }

    int last_digit = b.back();
    b.pop_back();
    return powmod(superPow(a, b), 10) * powmod(a, last_digit) % mod;
  }
};
