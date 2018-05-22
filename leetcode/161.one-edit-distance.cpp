#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    for (int i = 0; i < min(s.size(), t.size()); ++i) {
      if (s[i] == t[i]) {
        continue;
      }
      if (s.size() == t.size()) {
        return s.substr(i + 1) == t.substr(i + 1);
      } else if (s.size() < t.size()) {
        return s.substr(i) == t.substr(i + 1);
      } else {
        return s.substr(i + 1) == t.substr(i);
      }
    }
    return abs(static_cast<int>(s.size()) - static_cast<int>(t.size())) == 1;
  }
};
