class Solution {
public:
  /*
   * @param nums: A list of integers
   * @param k: An integer
   * @return: The maximum number inside the window at each moving
   */
  vector<int> maxSlidingWindow(vector<int> nums, int k) {
    deque<pair<int, int>> q;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {

      while (!q.empty() && q.front().first <= i - k) {
        q.pop_front();
      }

      while (!q.empty() && q.back().second < nums[i]) {
        q.pop_back();
      }

      q.push_back({i, nums[i]});

      if (i + 1 >= k) {
        res.push_back(q.front().second);
      }
    }
    return res;
  }
};
