class Solution {
public:
  /**
   * @param num: A list of integers
   * @return: An integer
   */
  int longestConsecutive(vector<int> &num) {
    unordered_set<int> s{num.begin(), num.end()};

    int maxStreak = 0;
    for (int n : num) {
      if (!s.count(n - 1)) {
        int streak = 1;

        while (s.count(n + streak)) {
          streak += 1;
        }

        maxStreak = max(maxStreak, streak);
      }
    }
    return maxStreak;
  }
};
