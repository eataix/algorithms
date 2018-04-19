#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (25.29%)
 * Total Accepted:    179.1K
 * Total Submissions: 708.2K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to
 * [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 *
 * [show hint]
 *
 * Hint:
 * Could you do it in-place with O(1) extra space?
 *
 * Related problem: Reverse Words in a String II
 *
 * Credits:
 * Special thanks to @Freezen for adding this problem and creating all test
 * cases.
 *
 */
class Solution {
  void reverseVector(vector<int> &nums, int start, int end) {
    while (start < end) {
      swap(nums[start++], nums[end--]);
    }
  }

public:
  void rotate(vector<int> &nums, int k) {
    if (nums.empty()) {
      return;
    }
    k %= nums.size();
    if (k == 0) {
      return;
    }
    reverseVector(nums, 0, nums.size() - 1);

    reverseVector(nums, 0, k - 1);
    reverseVector(nums, k, nums.size() - 1);
#ifdef DEBUG
    for (int i : nums) {
      cout << i << " ";
    }
    cout << endl;
#endif
  }
};

#ifdef DEBUG
int main() {
  vector<int> v{1, 2, 3, 4, 5, 6};
  Solution sol;
  sol.rotate(v, 6);
}
#endif
