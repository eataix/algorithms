#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (38.45%)
 * Total Accepted:    143.2K
 * Total Submissions: 372.4K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Example:
 *
 *
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 */
class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> s{nums.begin(), nums.end()};

    int res = 0;
    for (int num : nums) {
      if (!s.count(num - 1)) {
        int streak = 1;

        while (s.count(num + streak)) {
          streak += 1;
        }
        res = max(res, streak);
      }
    }
    return res;
  }
};
