#include <random>
#include <vector>
using namespace std;
/*
 * [912] Random Pick with Weight
 *
 * https://leetcode.com/problems/random-pick-with-weight/description/
 *
 * algorithms
 * Medium (39.21%)
 * Total Accepted:    101
 * Total Submissions: 248
 * Testcase Example:  '["Solution", "pickIndex"]\n[[[1]], []]'
 *
 * Given an array w of positive integers, where w[i] describes the weight of
 * index i, write a function pickIndex which randomly picks an index in
 * proportion to its weight.
 *
 * Note:
 *
 *
 * 1 <= w.length <= 10000
 * 1 <= w[i] <= 10^5
 * pickIndex will be called at most 10000 times.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * Output: [null,0]
 *
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
 * [[[1,3]],[],[],[],[],[]]
 * Output: [null,0,1,1,1,0]
 *
 *
 * Explanation of Input Syntax:
 *
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has one argument, the array w. pickIndex has no
 * arguments. Arguments are always wrapped with a list, even if there aren't
 * any.
 *
 *
 *
 *
 *
 *
 *
 */
class Solution {
  vector<int> dp;
  mt19937 rng{random_device{}()};
  uniform_int_distribution<int> uni;
  int tot = 0;

public:
  Solution(vector<int> w) {
    tot = 0;
    for (auto const &i : w) {
      tot += i;
      dp.push_back(tot);
    }

    uni = uniform_int_distribution<int>{0, tot - 1};
  }

  int pickIndex() {
    int targ = uni(rng);

    int lo = 0, hi = dp.size() - 1;
    while (lo != hi) {
      int mid = (lo + hi) / 2;
      if (targ >= dp[mid]) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
