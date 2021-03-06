#include <utility>
#include <vector>
using namespace std;
/*
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (32.67%)
 * Total Accepted:    31.9K
 * Total Submissions: 97.8K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You have a number of envelopes with widths and heights given as a pair of
 * integers (w, h). One envelope can fit into another if and only if both the
 * width and height of one envelope is greater than the width and height of the
 * other envelope.
 *
 *
 * What is the maximum number of envelopes can you Russian doll? (put one
 * inside other)
 *
 *
 * Example:
 * Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes
 * you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
 *
 */
class Solution {
public:
  int maxEnvelopes(vector<pair<int, int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.first < b.first ||
                  (a.first == b.first && a.second > b.second);
         });

    vector<int> dp;
    for (auto const &e : envelopes) {
      auto it = lower_bound(dp.begin(), dp.end(), e.second);
      if (it == dp.cend()) {
        dp.push_back(e.second);
      } else if (e.second < *it) {
        *it = e.second;
      }
    }
    return dp.size();
  }
};
