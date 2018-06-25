class Solution {
public:
  /**
   * @param nums: an array of integers
   * @return: the product of all the elements of nums except nums[i].
   */
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> left(nums.size());
    vector<int> right(nums.size());

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

    vector<int> res(nums.size());

    for (int i = 0; i < nums.size(); ++i) {
      res[i] = left[i] * right[i];
    }
    return res;
  }
};
