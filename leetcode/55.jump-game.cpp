#include <iostream>
#include <vector>
using namespace std;
/*
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (29.56%)
 * Total Accepted:    165.2K
 * Total Submissions: 558.9K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Determine if you are able to reach the last index.
 *
 * Example 1:
 *
 *
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 *
 *
 */
class Solution {
public:
  bool canJump(const vector<int> &nums) {
    int canReach = 0;
    for (int i = 0; i < nums.size() && i <= canReach; ++i) {
      canReach = max(canReach, i + nums[i]);
    }
    return canReach >= nums.size();
  }

  bool canJump2(const vector<int> &nums) {
    vector<bool> visited(nums.size(), false);

    visited[0] = true;
    for (int i = 0; i < nums.size(); ++i) {
      if (!visited[i]) {
        continue;
      }
      int canReach = nums[i];
      for (int j = i + 1; j < nums.size() && j <= i + canReach; ++j) {
        visited[j] = true;
      }
    }

    return visited.back();
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.canJump(vector<int>{2, 3, 1, 1, 4}) << endl;
  cout << sol.canJump(vector<int>{3, 2, 1, 0, 4}) << endl;
}
#endif
