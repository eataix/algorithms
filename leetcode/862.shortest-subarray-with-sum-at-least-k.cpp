#include <queue>
#include <vector>
using namespace std;
/*
 * [892] Shortest Subarray with Sum at Least K
 *
 * https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/
 *
 * algorithms
 * Hard (11.42%)
 * Total Accepted:    705
 * Total Submissions: 5.3K
 * Testcase Example:  '[1]\n1'
 *
 * Return the length of the shortest, non-empty, contiguous subarray of A with
 * sum at least K.
 *
 * If there is no non-empty subarray with sum at least K, return -1.
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: A = [1], K = 1
 * Output: 1
 *
 *
 *
 * Example 2:
 *
 *
 * Input: A = [1,2], K = 4
 * Output: -1
 *
 *
 *
 * Example 3:
 *
 *
 * Input: A = [2,-1,2], K = 3
 * Output: 3
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 50000
 * -10 ^ 5 <= A[i] <= 10 ^ 5
 * 1 <= K <= 10 ^ 9
 *
 *
 *
 *
 */
class Solution {
public:
  int shortestSubarray(vector<int> &A, int K) {
    int n = A.size();
    int res = n + 1;

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1] + A[i - 1];
    }

    deque<int> q;

    for (int i = 0; i <= n; ++i) {
      while (!q.empty() && dp[q.front()] <= dp[i] - K) {
        res = min(res, i - q.front());
        q.pop_front();
      }

      while (!q.empty() && dp[i] <= dp[q.back()]) {
        q.pop_back();
      }

      q.push_back(i);
    }

    return res <= n ? res : -1;
  }
};
