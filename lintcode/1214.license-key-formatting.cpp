#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
  /**
   * @param S: a string
   * @param K: a integer
   * @return: return a string
   */
  string licenseKeyFormatting(string &S, int K) {
    string res;

    int count = 0;

    for (auto it = S.crbegin(); it != S.crend(); ++it) {
      if (*it != '-') {
        res += toupper(*it);
        count += 1;

        if (count % K == 0) {
          res += '-';
        }
      }
    }

    if (res.back() == '-') {
      res.pop_back();
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
