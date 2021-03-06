#include <iostream>
#include <vector>
using namespace std;
/*
 * [276] Paint Fence
 *
 * https://leetcode.com/problems/paint-fence/description/
 *
 * algorithms
 * Easy (35.02%)
 * Total Accepted:    33.7K
 * Total Submissions: 96.3K
 * Testcase Example:  '3\n2'
 *
 * There is a fence with n posts, each post can be painted with one of the k
 * colors.
 *
 * You have to paint all the posts such that no more than two adjacent fence
 * posts have the same color.
 *
 * Return the total number of ways you can paint the fence.
 *
 * Note:
 * n and k are non-negative integers.
 *
 * Example:
 *
 *
 * Input: n = 3, k = 2
 * Output: 6
 * Explanation: Take c1 as color 1, c2 as color 2. All possible ways
 * are:
 *
 * post1  post2  post3
 * ⁠-----      -----  -----  -----
 * ⁠  1         c1     c1     c2
 * 2         c1     c2     c1
 * 3         c1     c2     c2
 * 4         c2     c1     c1 
 * ⁠  5         c2     c1     c2
 * 6         c2     c2     c1
 *
 *
 */
class Solution {
public:
  int numWays(int n, int k) {
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return k;
    }

    int same = k;
    int diff = k * (k - 1);

    for (int i = 3; i <= n; ++i) {
      int newDiff = (same + diff) * (k - 1);
      same = diff * 1;
      diff = newDiff;
    }

    return same + diff;
  }
};
