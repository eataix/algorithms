#include <limits>
#include <vector>
using namespace std;
/*
 * [650] 2 Keys Keyboard
 *
 * https://leetcode.com/problems/2-keys-keyboard/description/
 *
 * algorithms
 * Medium (45.47%)
 * Total Accepted:    22.3K
 * Total Submissions: 49K
 * Testcase Example:  '3'
 *
 *
 * Initially on a notepad only one character 'A' is present. You can perform
 * two operations on this notepad for each step:
 *
 * Copy All: You can copy all the characters present on the notepad (partial
 * copy is not allowed).
 * Paste: You can paste the characters which are copied last time.
 *
 *
 *
 *
 * Given a number n. You have to get exactly n 'A' on the notepad by performing
 * the minimum number of steps permitted. Output the minimum number of steps to
 * get n 'A'.
 *
 *
 * Example 1:
 *
 * Input: 3
 * Output: 3
 * Explanation:
 * Intitally, we have one character 'A'.
 * In step 1, we use Copy All operation.
 * In step 2, we use Paste operation to get 'AA'.
 * In step 3, we use Paste operation to get 'AAA'.
 *
 *
 *
 *
 * Note:
 *
 * The n will be in the range [1, 1000].
 *
 *
 */
class Solution {
public:
  int minSteps(int n) {
    vector<int> dp(n + 1, numeric_limits<int>::max());

    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        if (i % j == 0) {
          dp[i] = min(dp[i], dp[j] + (i / j));
        }
      }
    }
    return dp.back();
  }
};
