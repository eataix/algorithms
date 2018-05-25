#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
  string parseTernary(string expression) {
    stack<char> s;

    for (auto it = expression.crbegin(); it != expression.crend(); ++it) {
      char c = *it;

      if (!s.empty() && s.top() == '?') {
        s.pop();
        char first = s.top();
        s.pop();
        s.pop();
        char second = s.top();
        s.pop();
        s.push(c == 'T' ? first : second);
      } else {
        s.push(c);
      }
    }
    return string(1, s.top());
  }

  string parseTernary2(string expression) {
    string str = expression;
    while (str.size() > 1) {
      int i = str.find_last_of('?');
#ifdef DEBUG
      cout << str << " " << i << endl;
#endif
      str = str.substr(0, i - 1) +
            (str[i - 1] == 'T' ? str[i + 1] : str[i + 3]) + str.substr(i + 4);
    }
    return str;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  string s1{"T?2:3"};
  cout << sol.parseTernary(s1) << endl;
  string s2{"F?1:T?4:5"};
  cout << sol.parseTernary(s2) << endl;
  string s3{"T?T?F:5:3"};
  cout << sol.parseTernary(s3) << endl;
}
#endif
