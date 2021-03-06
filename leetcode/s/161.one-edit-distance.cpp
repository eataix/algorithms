#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    int m = s.size();
    int n = t.size();
    int mn = min(m, n);

    for (int i = 0; i < mn; ++i) {
      if (s[i] == t[i]) {
        continue;
      }
      if (m == n) {
        return s.substr(i + 1) == t.substr(i + 1);
      } else if (m < n) {
        return s.substr(i) == t.substr(i + 1);
      } else {
        return s.substr(i + 1) == t.substr(i);
      }
    }
    return abs(m - n) == 1;
  }
};
