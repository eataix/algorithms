class Solution {
public:
  /**
   * @param nums: an integer array
   * @return: nothing
   */
  void moveZeroes(vector<int> &nums) {
    int idx = -1;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        swap(nums[i], nums[idx + 1]);
        idx += 1;
      }
    }
  }
};
