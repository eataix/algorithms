/*
 * [632] Smallest Range
 *
 * https://leetcode.com/problems/smallest-range/description/
 *
 * algorithms
 * Hard (44.03%)
 * Total Accepted:    14.6K
 * Total Submissions: 33.2K
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * You have k lists of sorted integers in ascending order. Find the smallest
 * range that includes at least one number from each of the k lists.
 *
 * We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c
 * if b-a == d-c.
 *
 * Example 1:
 *
 * Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
 * Output: [20,24]
 * Explanation:
 * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 * List 2: [0, 9, 12, 20], 20 is in range [20,24].
 * List 3: [5, 18, 22, 30], 22 is in range [20,24].
 *
 *
 *
 *
 * Note:
 *
 * The given list may contain duplicates, so ascending order means >= here.
 * 1 k
 * ⁠-105 value of elements 5.
 * For Java users, please note that the input type has been changed to
 * List<List<Integer>>. And after you reset the code template, you'll see this
 * point.
 *
 *
 *
 */
class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    int curMax = numeric_limits<int>::min(), n = nums.size();
    vector<int> idx(n, 0);
    auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
      return a.first > b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
        cmp);
    for (int i = 0; i < n; ++i) {
      q.push({nums[i][0], i});
      idx[i] = 1;
      curMax = max(curMax, nums[i][0]);
    }
    vector<int> res{q.top().first, curMax};
    while (idx[q.top().second] < nums[q.top().second].size()) {
      int t = q.top().second;
      q.pop();
      q.push({nums[t][idx[t]], t});
      curMax = max(curMax, nums[t][idx[t]]);
      ++idx[t];
      if (res[1] - res[0] > curMax - q.top().first) {
        res = {q.top().first, curMax};
      }
    }
    return res;
  }
};
