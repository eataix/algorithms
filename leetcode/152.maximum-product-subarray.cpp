#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (26.77%)
 * Total Accepted:    137.9K
 * Total Submissions: 515.2K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest product.
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 *
 *
 * https://www.geeksforgeeks.org/maximum-product-subarray/
 */
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    vector<int> maxV(nums.size());
    vector<int> minV(nums.size());

    maxV[0] = nums[0];
    minV[0] = nums[0];

    int res = maxV[0];

    for (int i = 1; i < nums.size(); ++i) {
      maxV[i] = nums[i];
      minV[i] = nums[i];
      if (nums[i] > 0) {
        maxV[i] = max(maxV[i], nums[i] * maxV[i - 1]);
        minV[i] = min(minV[i], nums[i] * minV[i - 1]);
      } else {
        maxV[i] = max(maxV[i], nums[i] * minV[i - 1]);
        minV[i] = min(minV[i], nums[i] * maxV[i - 1]);
      }
      res = max(maxV[i], res);
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<int> v{2, 3, -2, 4};
  cout << sol.maxProduct(v) << endl;
}
#endif
