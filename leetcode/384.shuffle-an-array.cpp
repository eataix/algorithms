#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
/*
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (47.28%)
 * Total Accepted:    41.7K
 * Total Submissions: 88.1K
 * Testcase Example:
 * '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 *
 *
 * Example:
 *
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 *
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 *
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 *
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 *
 *
 */
class Solution {
  vector<int> copy;
  vector<int> working;
  default_random_engine generator;

public:
  Solution(vector<int> nums) {
    copy = nums;
    working = nums;
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return copy; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    for (int i = working.size() - 1; i >= 1; --i) {
      int j = uniform_int_distribution<int>{0, i}(generator);
      swap(working[j], working[i]);
    }
    return working;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

#ifdef DEBUG
int main() {
  vector<int> v{1, 2, 3, 4, 5, 6, 7};
  Solution obj{v};
  vector<int> param_1 = obj.reset();
  for (int i = 0; i < param_1.size(); ++i) {
    cout << i << " element is: " << param_1[i] << endl;
  }

  vector<int> param_2 = obj.shuffle();
  for (int i = 0; i < param_2.size(); ++i) {
    cout << i << " element is: " << param_2[i] << endl;
  }
  param_1 = obj.reset();
  for (int i = 0; i < param_1.size(); ++i) {
    cout << i << " element is: " << param_1[i] << endl;
  }
}
#endif
