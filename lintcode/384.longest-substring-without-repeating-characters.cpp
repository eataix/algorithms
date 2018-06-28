

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        unordered_map<char, int> m;
        
        int maxLen = 0;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            if (m.count(s[right])) {
                left = max(left, m[s[right]] + 1);
            }
            m[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

#include <algorithm>
using namespace std;
class Solution {
public:
  /**
   * @param n: the integer to be reversed
   * @return: the reversed integer
   */
  int reverseInteger(int n) {
    if (n == 0) {
      return 0;
    } else if (n < 0) {
      return -reverseInteger(abs(n));
    } else {
      int res = 0;

      while (n > 0) {

        int oldRes = res;
        res = res * 10 + n % 10;
        if (res / 10 != oldRes) {
          return 0;
        }
        n /= 10;
      }
      return res;
    }
  }
};
