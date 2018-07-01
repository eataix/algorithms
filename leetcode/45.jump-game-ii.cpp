#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
/*
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (26.11%)
 * Total Accepted:    119.6K
 * Total Submissions: 458.2K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * Example:
 *
 *
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 * Note:
 *
 * You can assume that you can always reach the last index.
 */
class Solution {
public:
  int jump(const vector<int> &nums) {
    int levels = 0;
    int maxIdxCurrLevel = 0;
    int maxIdxNextLevel = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > maxIdxCurrLevel) {
        maxIdxCurrLevel = maxIdxNextLevel;
        levels += 1;
      }

      maxIdxNextLevel = max(maxIdxNextLevel, nums[i] + i);
    }
    return levels;
  }

  int jump1(const vector<int> &nums) {
    int levels = 0;
    int lastOfCurrLevl = 0;
    int curr = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (i > lastOfCurrLevl) {
        lastOfCurrLevl = curr;
        levels += 1;
      }
      curr = max(curr, i + nums[i]);
    }
    return levels;
  }

  int jump3(const vector<int> &nums) {
    vector<bool> visited(nums.size(), false);
    vector<int> depth(nums.size(), nums.size());
    queue<int> q;

    q.push(0);
    visited[0] = true;
    depth[0] = 0;

    int currMax = 0;

    while (!q.empty()) {
      int idx = q.front();
      q.pop();

      for (int i = min(static_cast<int>(nums.size() - 1), idx + nums[idx]);
           i >= idx + 1; --i) {
        if (!visited[i]) {
          depth[i] = depth[idx] + 1;
          visited[i] = true;
          if (currMax < i + nums[i]) {
            currMax = i + nums[i];
            q.push(i);
          }
        } else {
          break;
        }
      }
    }

    return depth.back();
  }

  int jump2(const vector<int> &nums) {
    vector<int> dp(nums.size(), numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size() && j <= i + nums[i]; ++j) {
        dp[j] = min(dp[j], dp[i] + 1);
      }
    }

    return dp.back();
  }
};

#ifdef DEBUG
int main() {
  Solution sol;

  cout << sol.jump(vector<int>{1, 3, 2}) << endl;
  cout << sol.jump(vector<int>{2, 3, 1, 1, 4}) << endl;
}
#endif
