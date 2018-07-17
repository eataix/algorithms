#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
/*
 * [887] Minimum Cost to Hire K Workers
 *
 * https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
 *
 * algorithms
 * Hard (37.21%)
 * Total Accepted:    1.6K
 * Total Submissions: 4.4K
 * Testcase Example:  '[10,20,5]\n[70,50,30]\n2'
 *
 * There are N workers.  The i-th worker has a quality[i] and a minimum wage
 * expectation wage[i].
 *
 * Now we want to hire exactly K workers to form a paid group.  When hiring a
 * group of K workers, we must pay them according to the following rules:
 *
 *
 * Every worker in the paid group should be paid in the ratio of their quality
 * compared to other workers in the paid group.
 * Every worker in the paid group must be paid at least their minimum wage
 * expectation.
 *
 *
 * Return the least amount of money needed to form a paid group satisfying the
 * above conditions.
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
 * Input: quality = [10,20,5], wage = [70,50,30], K = 2
 * Output: 105.00000
 * Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
 * Output: 30.66667
 * Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers
 * seperately.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= K <= N <= 10000, where N = quality.length = wage.length
 * 1 <= quality[i] <= 10000
 * 1 <= wage[i] <= 10000
 * Answers within 10^-5 of the correct answer will be considered correct.
 *
 *
 *
 */
class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K) {
    vector<pair<double, double>> workers;
    for (int i = 0; i < quality.size(); ++i) {
      workers.push_back({static_cast<double>(wage[i]) / quality[i],
                         static_cast<double>(quality[i])});
    }
    sort(workers.begin(), workers.end());

    double res = numeric_limits<double>::max();
    double qsum = 0;
    priority_queue<int> pq;

    for (auto worker : workers) {
      qsum += worker.second;
      pq.push(worker.second);

      if (pq.size() > K) {
        qsum -= pq.top();
        pq.pop();
      }

      if (pq.size() == K) {
        res = min(res, qsum * worker.first);
      }
    }
    return res;
  }
};
