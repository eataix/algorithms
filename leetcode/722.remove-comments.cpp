#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> removeComments(vector<string> &source) {
    vector<string> res;

    bool inBlock = false;

    string sf;
    for (auto const &line : source) {
      for (int i = 0; i < line.size();) {
        if (inBlock) {
          if (i + 1 == line.size()) {
            i += 1;
          } else {
            if (line[i] == '*' && line[i + 1] == '/') {
              inBlock = false;
              i += 2;
            } else {
              i += 1;
            }
          }
        } else {
          if (i + 1 == line.size()) {
            sf += line[i++];
          } else {
            if (line[i] == '/' && line[i + 1] == '*') {
              inBlock = true;
              i += 2;
            } else if (line[i] == '/' && line[i + 1] == '/') {
              break;
            } else {
              sf += line[i++];
            }
          }
        }
      }
      if (!sf.empty() && !inBlock) {
        res.push_back(sf);
        sf.clear();
      }
    }
    return res;
  }
};
