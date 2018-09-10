class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &nums) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < nums.size(); ++i) {
      pq.push({nums[i], i});
    }

    vector<string> res(nums.size(), "");

    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (count == 0) {
        res[pq.top().second] = "Gold Medal";
      } else if (count == 1) {
        res[pq.top().second] = "Silver Medal";
      } else if (count == 2) {
        res[pq.top().second] = "Bronze Medal";
      } else {
        res[pq.top().second] = to_string(count + 1);
      }
      count += 1;
      pq.pop();
    }
    return res;
  }
};
