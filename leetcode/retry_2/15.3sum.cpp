#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.78%)
 * Total Accepted:    314.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 *
 *
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> nums) {
    if (nums.size() < 3) {
      return {};
    }

    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int currNum = nums[i];
      int currTarget = 0 - currNum;

      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {

        int numLeft = nums[left];
        int numRight = nums[right];
        int currSum = numLeft + numRight;

        if (currSum == currTarget) {
          res.push_back({numLeft, currNum, numRight});
#ifdef DEBUG
          cout << numLeft << " " << currNum << " " << numRight << endl;
#endif

          while (left < right && nums[left] == numLeft) {
            left += 1;
          }

          while (left < right && nums[right] == numRight) {
            right -= 1;
          }
        }

        if (currSum < currTarget) {
          left += 1;
        }

        if (currSum > currTarget) {
          right -= 1;
        }
      }
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.threeSum({-1, 0, 1, 2, -1, -4});
}
#endif
