#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [421] Maximum XOR of Two Numbers in an Array
 *
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (48.12%)
 * Total Accepted:    23.4K
 * Total Submissions: 48.7K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai <
 * 231.
 *
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 *
 * Could you do this in O(n) runtime?
 *
 * Example:
 *
 * Input: [3, 10, 5, 25, 2, 8]
 *
 * Output: 28
 *
 * Explanation: The maximum result is 5 ^ 25 = 28.
 *
 *
 */
class Solution {
public:
  int findMaximumXOR(vector<int> &nums) {
    int res = 0;
    int mask = 0;
    for (int i = 31; i >= 0; --i) {
      mask |= 1 << i;
      unordered_set<int> s;

      for (int num : nums) {
        s.insert(num & mask);
      }

      int t = res | (1 << i);
      for (int prefix : s) {
        if (s.find(t ^ prefix) != cend(s)) {
          res = t;
          break;
        }
      }
    }
    return res;
  }
};
