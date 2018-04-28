#include <iostream>
#include <vector>
using namespace std;
/*
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (50.28%)
 * Total Accepted:    146.5K
 * Total Submissions: 291.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 *
 * Given an array of n integers where n > 1, nums, return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array
 * does not count as extra space for the purpose of space complexity analysis.)
 */
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    if (nums.size() <= 1) {
      return nums;
    }

    vector<int> left(nums.size());
    vector<int> right(nums.size());
    vector<int> res(nums.size());

    int rightStartIdx = nums.size() - 1;
    for (int offset = 0; offset < nums.size(); ++offset) {
      if (offset == 0) {
        left[offset] = 1;
        right[rightStartIdx - offset] = 1;
      } else {
        left[offset] = left[offset - 1] * nums[offset - 1];
        right[rightStartIdx - offset] = right[rightStartIdx - offset + 1] *
                                        nums[rightStartIdx - offset + 1];
      }
    }

    for (int i = 0; i < nums.size(); ++i) {
      res[i] = left[i] * right[i];
    }

#ifdef DEBUG
    cout << "Left: " << endl;
    for (auto const &v : left) {
      cout << v << " ";
    }
    cout << endl;

    cout << "Right: " << endl;
    for (auto const &v : right) {
      cout << v << " ";
    }
    cout << endl;

    cout << "Product: " << endl;
    for (auto const &v : res) {
      cout << v << " ";
    }
    cout << endl;
#endif

    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<int> v{1, 2, 3, 4};
  sol.productExceptSelf(v);
}
#endif
