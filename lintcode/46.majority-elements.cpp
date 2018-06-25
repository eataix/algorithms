class Solution {
public:
  /*
   * @param nums: a list of integers
   * @return: find a  majority number
   */
  int majorityNumber(vector<int> &nums) {
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); ++i) {
      if (count == 0) {
        candidate = nums[i];
      }
      if (nums[i] == candidate) {
        count += 1;
      } else {
        count -= 1;
      }
    }
    return candidate;
  }
};
