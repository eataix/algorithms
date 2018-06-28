class Solution {
public:
  /**
   * @param nums: an array
   * @param k: an integer
   * @return: rotate the array to the right by k steps
   */
  vector<int> rotate(vector<int> &nums, int k) {
    if (nums.size() <= 1) {
      return nums;
    }
    k %= nums.size();

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    return nums;
  }
};
