#include <vector>
using namespace std;
/*
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (33.86%)
 * Total Accepted:    81K
 * Total Submissions: 239.1K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 *
 * Example:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 *
 * Note:  
 *
 *
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 *
 *
 */
class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> res{1};
    int i = 0;
    int j = 0;
    int k = 0;
    while (res.size() < n) {
      res.push_back(min(res[i] * 2, min(res[j] * 3, res[k] * 5)));
      if (res.back() == res[i] * 2) {
        i += 1;
      }
      if (res.back() == res[j] * 3) {
        j += 1;
      }
      if (res.back() == res[k] * 5) {
        k += 1;
      }
    }
    return res.back();
  }
};
