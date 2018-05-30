#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string compress(const string &str) {
    if (str.size() <= 1) {
      return str;
    }

    string res;
    char prev = str[0];
    res += prev;
    int count = 1;

    for (int i = 1; i < str.size(); ++i) {
      char curr = str[i];
      if (prev != curr) {
        res += to_string(count);

        prev = curr;
        res += prev;

        count = 1;
      } else {
        count += 1;
      }
    }

    res += to_string(count);

    return res.size() < str.size() ? res : str;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  string s1{"aabcccccaaa"};
  cout << sol.compress(s1) << endl;
  string s2{"aabbcc"};
  cout << sol.compress(s2) << endl;
  string s3{"aaaa"};
  cout << sol.compress(s3) << endl;
}
#endif
