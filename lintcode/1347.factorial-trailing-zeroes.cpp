class Solution {
public:
  /**
   * @param n: a integer
   * @return: return a integer
   */
  int trailingZeroes(int n) {
    int cnt = 0;

    while (n) {
      cnt += n / 5;
      n /= 5;
    }

    return cnt;
  }
};
