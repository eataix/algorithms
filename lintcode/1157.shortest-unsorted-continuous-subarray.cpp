class Solution {
public:
  /**
   * @param nums: an array
   * @return: the shortest subarray's length
   */
  int findUnsortedSubarray(vector<int> &nums) {
    int start = 0;
    int end = -1;

    int maxV = numeric_limits<int>::min();
    int minV = numeric_limits<int>::max();

    for (int offset = 0; offset < nums.size(); ++offset) {
      int left = offset;
      int right = nums.size() - 1 - offset;

      maxV = max(maxV, nums[left]);
      if (nums[left] != maxV) {
        end = left;
      }

      minV = min(minV, nums[right]);

      if (nums[right] != minV) {
        start = right;
      }
    }

    return end - start + 1;
  }
};
