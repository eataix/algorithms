#include <queue>
#include <string>
using namespace std;

class Solution {
public:
  /**
   * @param num: a string
   * @param k: an integer
   * @return: return a string
   */
  string removeKdigits(const string &num, int k) {
    deque<char> s;

    int keep = num.size() - k;
    for (char ch : num) {
      while (k > 0 && !s.empty() && ch < s.back()) {
        s.pop_back();
        k -= 1;
      }
      s.push_back(ch);
    }

    while (!s.empty() && s.front() == '0') {
      s.pop_front();
    }

    if (s.empty()) {
      return "0";
    } else {
      string res = "";

      while (!s.empty() && keep > 0) {
        res += s.front();
        s.pop_front();
        keep -= 1;
      }

      return res;
    }
  }
};
