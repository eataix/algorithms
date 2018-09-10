class Solution {
public:
  /**
   * @param list: The coins
   * @param k: The k
   * @return: The answer
   */
  int takeCoins(vector<int> &list, int k) {
    int n = list.size();
    vector<int> sums(n + 1, 0);

    for (int i = 0; i < n; ++i) {
      sums[i + 1] = sums[i] + list[i];
    }

    int res = 0;
    for (int i = 0; i <= k; ++i) {
      int left = i;
      int right = k - i;
      int curr = sums[n] - sums[n - right] + sums[left];
      res = max(res, curr);
    }
    return res;
  }
};
