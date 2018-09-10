class Solution {
public:
  /**
   * @param nums: a list of integer
   * @return: return a integer, denote  the maximum number of consecutive 1s
   */
  int findMaxConsecutiveOnes(vector<int> &nums) {
    queue<int> q;
    int k = 1;
    int res = 0;

    for (int l = 0, h = 0; h < nums.size(); ++h) {
      if (nums[h] == 0) {
        q.push(h);
      }

      if (q.size() > k) {
        l = q.front() + 1;
        q.pop();
      }

      res = max(res, h - l + 1);
    }
    return res;
  }
};
