#include <queue>
using namespace std;

class Solution {
public:
  /*
   * @param start: a string
   * @param end: a string
   * @param dict: a set of string
   * @return: An integer
   */
  int ladderLength(string &start, string &end, unordered_set<string> &dict) {
    dict.insert(end);

    queue<pair<string, int>> q;
    q.push({start, 1});

    while (!q.empty()) {
      auto p = q.front();
      q.pop();

      string str = p.first;
      cout << str << endl;
      int level = p.second;

      if (str == end) {
        return level;
      }

      string newStr{str};
      for (int i = 0; i < newStr.size(); ++i) {
        for (char ch = 'a'; ch <= 'z'; ++ch) {
          if (str[i] != ch) {
            newStr[i] = ch;
            if (dict.count(newStr)) {
              q.push({newStr, level + 1});
              dict.erase(newStr);
            }
          }
        }
        newStr[i] = str[i];
      }
    }

    return 0;
  }
};
