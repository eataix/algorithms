#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param s: The data stream
   * @return: Return the judgement stream
   */
  vector<int> getStream(const string &s) {
    vector<int> res(s.size(), 0);

    unordered_set<char> set;

    for (int i = 0; i < s.size(); ++i) {
      char ch = s[i];

      if (set.find(ch) == set.cend()) {
        set.insert(ch);
      } else {
        set.erase(ch);
      }

      res[i] = set.size() > 1 ? 0 : 1;
      cout << "i: " << i << " " << res[i] << endl;
    }

    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.getStream("aba");
}
#endif
