#include <algorithm>
#include <vector>
using namespace std;
/*
 * [683] K Empty Slots
 *
 * https://leetcode.com/problems/k-empty-slots/description/
 *
 * algorithms
 * Hard (33.63%)
 * Total Accepted:    17K
 * Total Submissions: 50.7K
 * Testcase Example:  '[1,3,2]\n1'
 *
 *
 * There is a garden with N slots. In each slot, there is a flower. The N
 * flowers will bloom one by one in N days. In each day, there will be exactly
 * one flower blooming and it will be in the status of blooming since then.
 *
 *
 *
 * Given an array flowers consists of number from 1 to N. Each number in the
 * array represents the place where the flower will open in that day.
 *
 *
 *
 * For example, flowers[i] = x means that the unique flower that blooms at day
 * i will be at position x, where i and x will be in the range from 1 to N.
 *
 *
 *
 * Also given an integer k, you need to output in which day there exists two
 * flowers in the status of blooming, and also the number of flowers between
 * them is k and these flowers are not blooming.
 *
 *
 *
 * If there isn't such day, output -1.
 *
 *
 * Example 1:
 *
 * Input:
 * flowers: [1,3,2]
 * k: 1
 * Output: 2
 * Explanation: In the second day, the first and the third flower have become
 * blooming.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * flowers: [1,2,3]
 * k: 1
 * Output: -1
 *
 *
 *
 *
 * Note:
 *
 * The given array will be in the range [1, 20000].
 *
 *
 */
class Solution {
  int query(const vector<int> &sum, int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) {
      res += sum[i];
    }
    return res;
  }
  void update(vector<int> &sum, int i) {
    for (; i < sum.size(); i += i & -i) {
      sum[i] += 1;
    }
  }

public:
  int kEmptySlots(vector<int> &flowers, int k) {
    vector<int> sum(flowers.size() + 1, 0);
    for (int i = 0; i < flowers.size(); ++i) {
      int j = flowers[i];
      update(sum, j);

      if (j - k - 1 > 0) {
        int a = query(sum, j - k - 2);
        int b = query(sum, j - k - 1);
        int c = query(sum, j - 1);

        if (b - a == 1 && c - b == 0) {
          return i + 1;
        }
      }

      if (j + k + 1 < sum.size()) {
        int a = query(sum, j);
        int b = query(sum, j + k);
        int c = query(sum, j + k + 1);

        if (b - a == 0 && c - b == 1) {
          return i + 1;
        }
      }
    }
    return -1;
  }

  int kEmptySlots2(vector<int> &flowers, int k) {
    vector<int> days(flowers.size());
    for (int i = 0; i < flowers.size(); ++i) {
      days[flowers[i] - 1] = i + 1;
    }

    auto left = 0;
    auto right = k + 1;
    int res = flowers.size() + 1;

    for (int i = 1; right < days.size(); i++) {
      // current days[i] is valid, continue scanning
      if (days[i] > days[left] && days[i] > days[right]) {
        continue;
      }
      // reach boundary of sliding window, since previous number are all valid,
      // record result
      if (i == right) {
        res = min(res, max(days[left], days[right]));
      }
      // not valid, move the sliding window
      left = i;
      right = left + k + 1;
    }

    return res == flowers.size() + 1 ? -1 : res;
  }
};
