#include <queue>

using namespace std;

class Solution {
public:
  /**
   * @param nums: an array
   * @param k: an integer
   * @return: the maximum average value
   */
  double findMaxAverage(vector<int> &nums, int k) {
    queue<int> q;

    long total = 0;
    int idx = 0;
    while (q.size() < k) {
      total += nums[idx];
      q.push(nums[idx]);

      idx += 1;
    }

    long best = total;

    while (idx < nums.size()) {
      total -= q.front();
      q.pop();
      total += nums[idx];
      q.push(nums[idx]);
      best = max(best, total);

      idx += 1;
    }

    return static_cast<double>(best) / k;
  }
};
