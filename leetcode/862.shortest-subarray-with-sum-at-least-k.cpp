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
    vector<long long> totalSum(A.size() + 1, 0);
    for (int len = 1; len <= A.size(); ++len) {
      totalSum[len] = totalSum[len - 1] + A[len - 1];
    }

    deque<pair<int, int>> q;
    int res = A.size() + 1;
    for (int i = 0; i < totalSum.size(); ++i) {
      while (!q.empty() && totalSum[i] - q.front().second >= K) {
        res = min(res, i - q.front().first);
        q.pop_front();
      }

      while (!q.empty() && q.back().second >= totalSum[i]) {
        q.pop_back();
      }
      q.push_back({i, totalSum[i]});
    }
    return res > A.size() ? -1 : res;
  }
};
