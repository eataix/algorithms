#include <vector>
using namespace std;
/*
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (25.54%)
 * Total Accepted:    80.3K
 * Total Submissions: 314.2K
 * Testcase Example:  '[1,0,2]'
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 *
 * You are giving candies to these children subjected to the following
 * requirements:
 *
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 *
 *
 * What is the minimum candies you must give?
 *
 * Example 1:
 *
 *
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 *
 *
 * Example 2:
 *
 *
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * ⁠            The third child gets 1 candy because it satisfies the above
 * two conditions.
 *
 *
 */
class Solution {
public:
  int candy(vector<int> &ratings) {
    if (ratings.size() <= 1) {
      return ratings.size();
    }

    int cntDown = 0;
    int prev = 1;
    int total = 1;

    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i - 1] <= ratings[i]) {
        if (cntDown > 0) {
          total += cntDown * (cntDown + 1) / 2;
          if (cntDown >= prev) {
            total += cntDown + 1 - prev;
          }

          cntDown = 0;
          prev = 1;
        }

        prev = ratings[i] == ratings[i - 1] ? 1 : prev + 1;
        total += prev;
      } else {
        cntDown += 1;
      }
    }
    if (cntDown > 0) {
      total += cntDown * (cntDown + 1) / 2;
      if (prev <= cntDown) {
        total += cntDown + 1 - prev;
      }
    }
    return total;
  }

  int candy3(vector<int> &ratings) {
    if (ratings.empty()) {
      return 0;
    }

    int res = 1;
    int pre = 1;
    int cnt = 0;

    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] >= ratings[i - 1]) {
        if (cnt > 0) {
          res += cnt * (cnt + 1) / 2;

          if (cnt >= pre) {
            res += cnt - pre + 1;
          }

          cnt = 0;
          pre = 1;
        } else {
          if (ratings[i] == ratings[i - 1]) {
            pre = 1;
          } else {
            pre += 1;
          }
          res += pre;
        }
      } else {
        cnt += 1;
      }
    }

    if (cnt > 0) {
      res += cnt * (cnt + 1) / 2;
      if (cnt >= pre) {
        res += cnt - pre + 1;
      }
    }
    return res;
  }

  int candy2(vector<int> &ratings) {
    if (ratings.empty()) {
      return 0;
    }

    vector<int> res(ratings.size(), 1);

    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) {
        res[i] = res[i - 1] + 1;
      }
    }

    int sum = res.back();
    for (int i = ratings.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        res[i] = max(res[i], res[i + 1] + 1);
      }
      sum += res[i];
    }

    return sum;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<int> rankings{1, 0, 2};
  sol.candy(rankings);
}
#endif
