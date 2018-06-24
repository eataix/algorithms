#include <unordered_set>
using namespace std;

class Solution {
public:
  /**
   * @param s: The data stream
   * @return: Return the judgement stream
   */
  vector<int> getStream(string &s) {
    unordered_set<char> window;

    vector<int> res;
    for (char ch : s) {
      if (window.count(ch)) {
        window.erase(ch);
      } else {
        window.insert(ch);
      }

      if (window.size() <= 1) {
        res.push_back(1);
      } else {
        res.push_back(0);
      }
    }
    return res;
  }
};
