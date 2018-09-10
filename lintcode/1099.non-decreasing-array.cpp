class Solution {
public:
  bool checkPossibility(vector<int> &nums) {
    int cnt = 0;
    for (int i = 1; i < nums.size() && cnt <= 1; ++i) {
      if (nums[i - 1] > nums[i]) {
        cnt += 1;
        if (i - 2 < 0 || nums[i - 2] <= nums[i]) {
          nums[i - 1] = nums[i];
        } else {
          nums[i] = nums[i - 1];
        }
      }
    }
    return cnt <= 1;
  }
};
