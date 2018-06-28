class Solution {
public:
  /**
   * @param nums: an array of Integer
   * @param target: target = nums[index1] + nums[index2]
   * @return: [index1 + 1, index2 + 1] (index1 < index2)
   */
  vector<int> twoSum(vector<int> &nums, int target) {
    int i = 0;
    int j = nums.size() - 1;

    while (i < j) {
      int sum = nums[i] + nums[j];

      if (sum == target) {
        return {i + 1, j + 1};
      }

      if (sum < target) {
        i += 1;
      }

      if (sum > target) {
        j -= 1;
      }
    }
  }
};
