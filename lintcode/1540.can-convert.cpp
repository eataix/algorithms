class Solution {
public:
  /**
   * @param s: string S
   * @param t: string T
   * @return: whether S can convert to T
   */
  bool canConvert(string &longer, string &shorter) {
    int m = longer.size();
    int n = shorter.size();
    int i = 0;
    int j = 0;
    while (i < m && j < n) {
      if (longer[i] == shorter[j]) {
        j += 1;
      }
      i += 1;
    }
    return j == n;
  }
};
